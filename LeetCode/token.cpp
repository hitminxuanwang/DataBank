#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	/*string str="this,is,a test token";
	vector<string> sstr;
	istringstream iss(str);
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(sstr));
	for (int i = 0; i < sstr.size(); ++i)
	{
		cout<<sstr[i]<<endl;
	}
	*/
	string input = "abc,def,ghi";
	istringstream ss(input);
	string token;

	while(getline(ss, token, ',')) {
   	 cout << token << '\n';
	}

	
	return 0;
}