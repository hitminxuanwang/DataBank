#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
		int n=s.length();
		int m=p.length();
		bool** dp=new bool*[n+1];
		for(int i=0;i<=n;i++)
		{
			dp[i]=new bool[m+1];
		}
		dp[0][0]=true;
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=false;
		}
		for(int i=1;i<=m;i++)
		{
			dp[0][i]=false;
			if(p[i-1]=='*')
			{
				dp[0][i]=dp[0][i-2];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{

				dp[i][j]=false;
				if(p[j-1]=='*')
				{
					if(dp[i][j-2]||((s[i-1]==p[j-2]||p[j-2]=='.') && dp[i-1][j]))
						dp[i][j]=true;
				}
				else if(dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.'))
				{
					dp[i][j]=true;
				}

			}
		}
		bool flag=dp[n][m];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}

		for(int i=0;i<=n;i++)
		{
			delete [] dp[i];
		} 
		delete[] dp;
		return flag; 
    }
};
int  main(){
	Solution solution;
	string str1="aa";
	string str2="a*q";
	bool result=solution.isMatch(str1,str2);
	if (result) cout<<"True"<<endl;
		else cout<<"False"<<endl;
	system("pause");
	return 0;


}