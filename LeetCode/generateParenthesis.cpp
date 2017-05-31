#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	void produce(int l,int r,string str,vector<string>& res){
		if (l==0 && r==0)
		{
			res.push_back(str);
		}
		if (l>0)
		{
			produce(l-1,r,str+"(",res);
		}
		if (r>l)
		{
			produce(l,r-1,str+")",res);
		}

	}
		vector<string> generateParenthesis(int n){
			vector<string> res;
			produce(n,n,"",res);
			return res;			
	}
	
};

int main()
{
	Solution solution;
	vector<string> res=solution.generateParenthesis(3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}