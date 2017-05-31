#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	vector<int> plusOne(vector<int> &digits){
		int carray=1;
		int i=digits.size()-1;
		while(carray!=0 && i>=0){
			int result=digits[i]+carray;
			digits[i]=result%10;
			carray=result/10;
			--i;
		}
		if (i<0)
		{
			if(carray){
				digits.push_back(0);
				for (int j =digits.size()-1; j >0; --j)
				{
					digits[j]=digits[j-1];
				}
				digits[0]=carray;
			}
		}
		return digits;


	}
	
};




int main(int argc, char const *argv[])
{
	/* code */
	Solution solution;
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(8);
	solution.plusOne(digits);
	for (int i = 0; i < digits.size(); ++i)
	{
		cout<<digits[i];
	}

	return 0;
}