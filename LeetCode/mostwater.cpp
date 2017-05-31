#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int maxArea(vector<int> &hight){
			int i=0,j=hight.size()-1;
			int result=0;
			while(i<j){
				int area=min(hight[j],hight[i])*(j-i);
				result=max(result,area);
				if(hight[i]<hight[j])
					++i;
				else
					--j;
			}
			return result;
		}
};
int main(int argc, char const *argv[])
{
	Solution solution;
	vector <int> hight;
	hight.push_back(2);
	hight.push_back(3);
	hight.push_back(10);
	hight.push_back(5);
	hight.push_back(7);
	hight.push_back(8);
	hight.push_back(9);
	int result=solution.maxArea(hight);
	cout<<result<<endl;
	return 0;
}
