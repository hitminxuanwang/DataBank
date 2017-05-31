#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void testfunction(ifstream &fin){
	string str="";
	getline(fin,str);
	//fin.close();
	cout<<str+"   in test function"<<endl;
}
int main(int argc, char const *argv[])
{
	string str;
	ifstream fin("string.txt");
	testfunction(fin);
	getline(fin,str);
	//cout<<str<<endl;
	cout<<str+"   in main function"<<endl;
	return 0;
}