// MultiEncode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost\filesystem.hpp>
#include <boost\foreach.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <math.h>
#include <bitset>
#include <cv.h>
#include <opencv.hpp>
#include <cvaux.h>
#include <highgui.h>
#include <windows.h>
using namespace std;
using namespace boost::filesystem;
using namespace cv;


#ifdef _DEBUG
#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_imgproc2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")

#else
#pragma comment(lib, "opencv_core2411.lib")
#pragma comment(lib, "opencv_imgproc2411.lib")
#pragma comment(lib, "opencv_highgui2411.lib")
#endif // _DEBUG


#define NUMBER 2700
#define N 17
#define Pi 3.141592653


struct contour
{
	int x;
	int y;
	int minx;
	int miny;
	int maxx;
	int maxy;
	vector<pair<int, int>> contourpoint;
	//bitset<192> bits;
};


static void write(FileStorage& fs, const std::string&, const RotatedRect& x)
{
	fs << "{" << "center" << x.center << "size" << x.size << "angle" << x.angle << "}";
}

FileStorage &operator<<(FileStorage &fs,const RotatedRect &x){

	fs << "{" << "center" << x.center << "size" << x.size << "angle" << x.angle << "}";
	return fs;
}
FileNode  &operator>>(FileNode &fs, RotatedRect &x){

	fs["center"]>>x.center;
	fs["size"]>>x.size;
	fs["angle"] >> x.angle;
	return fs;
}



map<string, vector<contour>> data;
map<string, vector<RotatedRect>> edata;
map<string, bitset<NUMBER> > bitcode;
//map <string, vector<vector<contour>>> multidata;
map <string, vector<vector<vector<pair<int, int>>>>> image;
//map<string, Feature> conto;
void split(vector<string> & vec, string s){
	istringstream ss(s);
	string token;
	while (getline(ss, token, '\t')){
		vec.push_back(token);
	}
}

vector<pair<int, int> > rotation(int x, int y, int x0, int y0){
	vector<pair<int, int>> result;
	int rx, ry;
	for (int i = 0; i <=N; i++)
	{
		rx = round(x0 + (x - x0)*cos(i * 10*Pi/180) - (y - y0)*sin(i * 10*Pi/180));
		ry = round(y0 + (y - y0)*cos(i * 10*Pi/190) + (x - x0)*sin(i * 10*Pi/180));
		result.push_back(pair<int, int>(rx, ry));
	}
	return result;
}






int main()
{
	

	//string fname = "data.xml";
	//FileStorage ffs(fname, FileStorage::READ);
	//ffs.open(fname, FileStorage::READ);

	//FileNode n = ffs["Mapping"];
	//FileNodeIterator iter = n.begin(), iter_end = n.end();
	//map<string, vector<RotatedRect>> ndata;
	//for( ; iter!=iter_end; iter++)
	//{
	//	string key = (*iter).name();
	//	FileNodeIterator it = (*iter).begin(), it_end = (*iter).end();
	//	vector<RotatedRect> ro;
	//	for (; it!=it_end; it++)
	//	{
	//		RotatedRect tmp;
	//		FileNode item = *it;
	//		item >> tmp;
	//		ro.push_back(tmp);
	//	}
	//	string str = key.substr(1) + ".jpg";
	//	ndata.insert(map<string,vector<RotatedRect>>::value_type(str,ro));

	//}



	path current_dir("./contour");
	ofstream ffout("efeature.txt");
	directory_iterator end_iter;
	int count = 0; //vector<contour> record;
	for (directory_iterator iter(current_dir); iter != end_iter; ++iter){
		string name = iter->path().filename().string();
		ifstream fin(current_dir.string() + "/" + name);
		string  s;
		getline(fin, s);
		getline(fin, s);
		if (fin.eof()) continue;
		//count = atoi(s.c_str());
		contour cont;
		vector<contour> record;
		while (true)
		{
			getline(fin, s);
			if (fin.eof()) break;
			if (s.find('\t') == string::npos)  { record.push_back(cont); cont.contourpoint.clear(); continue; }
			else
			{
				vector<string> temp;
				split(temp, s);
				pair<int, int> point(atoi(temp[0].c_str()), atoi(temp[1].c_str()));
				cont.contourpoint.push_back(point);
			}
		}
		record.push_back(cont);
		data.insert(map<string, vector<contour>>::value_type(name.substr(0, name.find('_')), record));
	}
	//Do Fit 
	for (map<string,vector<contour>>::iterator iter=data.begin(); iter!=data.end(); iter++)
	{
		vector<contour> tmp = iter->second;
		vector<RotatedRect> final_efeature;
		for (int j = 0; j < tmp.size(); j++)
		{
			contour ell = tmp[j];
			vector<Point> edata;
			for (int k = 0; k < ell.contourpoint.size(); k++)
			{
				Point A;
				A.x = ell.contourpoint[k].first;
				A.y = ell.contourpoint[k].second;
				edata.push_back(A);
			}

			if (edata.size() < 5) continue;
			RotatedRect ef = fitEllipse(edata);
			final_efeature.push_back(ef);
		}
		edata.insert(map<string,vector<RotatedRect>>::value_type(iter->first,final_efeature));
	}
	//for (map<string,vector<RotatedRect>>::iterator iter=edata.begin(); iter!=edata.end(); iter++)
	//{
	//	ffout << iter->first << "\t";
	//	for (int i = 0; i < iter->second.size(); i++)
	//	{
	//		ffout<<iter->second[i].center<<"\t";
	//		ffout << iter->second[i].size << "\t";
	//		ffout << iter->second[i].angle << "\t";
	//	}
	//	ffout << endl;
	//}
	string filename = "data.xml";
	FileStorage fs(filename, FileStorage::WRITE);
	fs << "Mapping" << "{";

	

	int basic=0;
	for (map<string,vector<RotatedRect>>::iterator iter=edata.begin(); iter!=edata.end(); iter++)
	{
		if (iter->second.size() < 1) continue;
		fs <<"t"+iter->first.substr(0,iter->first.find('.'))<<"[";
		for (int i = 0; i <iter->second.size(); i++)
		{
			fs << iter->second[i];
		}
		fs << "]";


	}
	fs << "}";
	fs.release();
	ofstream fcout("code.txt");
	for (map<string,vector<contour>>::iterator iter = data.begin(); iter != data.end(); iter++){
		int number = iter->second.size();
		for (int i = 0; i <number; i++)
		{
			vector<int> x, y;
			for (int j = 0; j <iter->second[i].contourpoint.size(); j++)
			{
				x.push_back(iter->second[i].contourpoint[j].first);
				y.push_back(iter->second[i].contourpoint[j].second);
			}
			iter->second[i].minx = *min_element(x.begin(),x.end());
			iter->second[i].maxx = *max_element(x.begin(),x.end());
			iter->second[i].miny = *min_element(y.begin(),y.end());
			iter->second[i].maxy = *max_element(y.begin(), y.end());
			iter->second[i].x = (iter->second[i].maxx + iter->second[i].minx) >> 1;
			iter->second[i].y = (iter->second[i].maxy + iter->second[i].miny) >> 1;
		}
	}
	for (map<string,vector<contour>>::iterator iter=data.begin();iter!=data.end(); iter++)
	{
		vector<contour> record = iter->second;
		vector<vector<contour>> rorecord;
		//vector<vector<pair<int, int>>> pointgroup;
		vector<vector<vector<pair<int, int>>>> iellipse;
		//map <string,vector<vector<vector<pair<int, int>>>>> image;
		int number = record.size();
		for (int i = 0; i < number; i++)
		{
			contour ellipse = record[i];
			vector<vector<pair<int, int>>> pointgroup;
			for (int j = 0; j < ellipse.contourpoint.size(); j++)
			{
				vector<pair<int,int>> temp=rotation(ellipse.contourpoint[j].first,ellipse.contourpoint[j].second,ellipse.x,ellipse.y);
				pointgroup.push_back(temp);
			}
			iellipse.push_back(pointgroup);
		}
		image.insert(map<string, vector<vector<vector<pair<int,int>>>>>::value_type(iter->first, iellipse));
	}
	for (map<string, vector<vector<vector<pair<int, int>>>>>::iterator iter = image.begin(); iter != image.end(); iter++){
		vector<vector<vector<pair<int, int>>>> vec = iter->second;
		bitset<NUMBER> flag;
		for (int i = 0; i < NUMBER; i++)
		{
			flag[i] = 0;
		}
		vector<int> x, y;
		for (int number = 0; number <=N; number++)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				for (int j = 0; j < vec[i].size(); j++)
				{
					x.push_back(vec[i][j][number].first);
					y.push_back(vec[i][j][number].second);
				}

			}
			int minx = *min_element(x.begin(),x.end());
			int maxx = *max_element(x.begin(),x.end());
			int miny = *min_element(y.begin(), y.end());
			int maxy = *max_element(y.begin(),y.end());
			x.clear();
			y.clear();
			//cout << minx << "\t" << maxx << "\t" << miny << "\t" << maxy << "\t";
			for (int i = max(minx,0)/10; i < maxx/10 && i<75 ; i++)
			{
				flag[i + 150 * number] = 1;
			}
			for (int i = max(miny,0)/10; i < maxy/10 && i<75; i++)
			{
				flag[i + 75 + 150 * number] = 1;
			}
		}
		bitcode.insert(map<string, bitset<NUMBER>>::value_type(iter->first, flag));
	}

	for (map<string,bitset<NUMBER>>::iterator iter=bitcode.begin(); iter!=bitcode.end(); iter++)
	{
		
		fcout << iter->first << "\t";
		for (int i = 0; i < NUMBER; i++)
		{
			fcout << iter->second[i];
		}
		fcout << endl;

	}





	system("pause");
	return 0;
}
