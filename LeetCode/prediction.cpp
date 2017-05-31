#include <algorithm>
#include <iostream>
#include <windows.h>
using namespace std;
int main(int argc, char const *argv[])
{
	const unsigned arraySize=32768;
	int data[arraySize];
	for (unsigned i = 0; i < arraySize; ++i)
	{
		data[i]=std::rand()%256;
	}

	std::sort(data,data+arraySize);
	DWORD start,end;
	start=GetTickCount();
	long long sum=0;
	for (unsigned i = 0; i < 100000; ++i)
	{
		for (unsigned j = 0; j < arraySize; ++j)
		{
			if(data[j]>=128)
				sum+=data[j];
		}
	}
	end=GetTickCount();
	cout<<end-start<<endl;


	return 0;
}