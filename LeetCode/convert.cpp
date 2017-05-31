#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

void split(vector<string> &vec, string s){
	istringstream ss(s);
	string token;
	while (getline(ss, token, ',')) {
		vec.push_back(token);
	}


}
int main(int argc, char const *argv[])
{

	ifstream fin("mail.csv");
	vector<string> temp;
	vector< vector <string> > data;
	string str;
	while (true){
		temp.clear();
		getline(fin, str);
		if (fin.eof()) break;
		split(temp, str);
		data.push_back(temp);
	}
	ofstream fout("mail-all.txt");
	for (int i = 0; i < data.size(); ++i)
	{
		//fout << data[i][0] << "\t";
	for (int j = 3; j < data[i].size(); ++j)
	{
		if (data[i][j].length()!=0)
		fout<<data[i][j]<<endl;
	}
	fout<<endl;
	}




	return 0;
}