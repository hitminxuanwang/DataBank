#include<stdio.h>
#include<windows.h>
using namespace std;
int main(void)
{
	string bn;
	do{
		cout<<"你觉得布鸟帅吗？（‘帅’：‘不帅’";
		cin<<bn;

	} while (bn != "帅");
	system("pause");
	return 0;
}  
