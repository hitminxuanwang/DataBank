#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <windows.h>
using namespace std;
bool prinum(long long number){

	int startnumber=int(sqrt(number));
	for(int i=startnumber;i>=3;--i){
		if(i%2!=0){
			if(number%i==0)
				return false;
		}
		}
			return true;
}


int main(int argc, char const *argv[])
{
	//899808659
	long long maxnum=899808658;
	DWORD start,end;
	start=GetTickCount();
	bool flag=false;
	long long s=maxnum;
	for(;;--s){
		flag=prinum(s);
		//cout<<flag<<endl;
		if(flag==true)
			break;
	}
	cout<<s<<endl;
	end=GetTickCount();
	cout<<end-start;
	return 0;
	
}