#include <iostream>
using namespace std;
class Solution
{
public:
	bool isMatch(string s,string p){
		int m=s.length();
		int n=p.length();
		bool flag=false;
		bool ** dp=new bool*[m+1];
		for (int i = 0; i <=m; ++i)
		{
			dp[i]=new bool[n+1];
				dp[i][n]=false;
	
		}
		dp[m][n]=true; 
		for (int j = n-1; j >=0; --j)
		{
			dp[m][j]=false;
			if(p[j]=='*'){
				dp[m][j-1]=dp[m][j+1];
				j--;
			}

		}
		for (int i = m-1; i >=0; --i)
		{
			for (int j = n-1; j >=0; --j)
			{
				dp[i][j]=false;
				if(p[j]!='*'){ 
					if((p[j]==s[i] || '.'==p[j]) && dp[i+1][j+1]==true)
						dp[i][j]=true;
				}
				else
						if (dp[i][j+1]==true ||(( dp[i+1][j-1])&&(s[i]==p[j-1]||'.'==p[j-1])))
							dp[i][--j]=true;
			}
		}
		flag=dp[0][0];
		for (int i = 0; i < m+1; ++i)
		{
			delete [] dp[i];
		}
		delete [] dp;
		return flag;
    }
	
};
int main(int argc, char const *argv[])
{
	Solution solution;
	string s="aab";
	string p="c*a*b";
	bool result=solution.isMatch(s,p);
	if(result)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}