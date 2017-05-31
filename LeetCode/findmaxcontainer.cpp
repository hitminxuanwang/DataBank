#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{	
	public:
	int container(vector<int> &hight,int i,int j){
		if(j-i<=0)
			return 0;
		else if(j-i==1)
			return min(hight[i],hight[j]);
		else {
			int middle=(j+i)/2;
			int maxarea=0;
			for (int p = middle-1; p>=i; --p)
			{
				for (int q = middle; q <=j; ++q)
				{
					if(min(hight[p],hight[q])*(q-p)>maxarea){
						maxarea=min(hight[p],hight[q])*(q-p);
					}

				}
				
			}
			return max(maxarea,max(container(hight,i,middle),container(hight,middle,j)));
		}
	}
	int maxArea(vector<int> &hight){
		int first=0;
		int end=hight.size()-1;
		return container(hight,first,end) ;
	}

};
int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> hight;
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