#include <vector>
#include <list>
#include <time.h>
#include <iostream>
#include <windows.h>
using namespace std;


int main(int argc, char const *argv[])
{
	//time_t start,end;
	//cout<<clock()<<endl;
	//time(&start);
	//Sleep(5000);
	//time(&end);
	vector<float> vec;
	//cout<<end-start<<endl;
	/*DWORD start, stop;
    start = GetTickCount();
    for (int i = 0; i < 10000; ++i)
    {
    	vec.push_back(1/3);
    }
    double data=0.00; 
    for (int i = 0; i < 10000; ++i)
    {
    	
    	for (int j=0; j < vec.size(); ++j)
    	{
    		data+=vec[j];
    	}
    	
    }
    cout<<data<<endl;
    stop = GetTickCount();
    cout<<stop-start<<endl;

    vec.clear();*/
    DWORD open, close;
    open = GetTickCount();
    //list<float> lis;
    for (int i = 0; i < 10000; ++i)
    {
    	vec.push_back(1/3);
    }
    double meta=0.00; 
    for (int i = 0; i < 10000; ++i)
    {
    	for (int j=vec.size()-1; j>=0; --j)
    	{
    		meta+=vec[j];
    	}
    	
    }
    cout<<meta<<endl;
    close = GetTickCount();
    cout<<close-open<<endl;
   




	return 0;
}