#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Solution{
public:
	bool isMatch(string s,string p){
			int slen=s.length();
			int plen=p.length();
			bool flag=false;
			bool** dp= new bool*[slen+1];
			for (int i = 0; i < slen + 1 ; ++i)
			{
				dp[i]=new bool[plen+1];
			}
			for (int i = 0; i < slen+1; ++i)
			{
					dp[i][0]=false;
			}
			dp[0][0]=true;
			for (int i = 1; i < plen+1; ++i)
			{
				dp[0][i]=false;
				if (p[i-1]=='*')
				{
					dp[0][i]=dp[0][i-2];
				}
			}//initial
			for (int i = 1; i < slen + 1; ++i)
			{
				for (int j = 1; j < plen+1; ++j)
				{
					dp[i][j]=false;
					if(p[j-1]=='*'){
						if (dp[i][j-2] or ((p[j-2]=='.' or p[j-2]==s[i-1]) and ( dp[i-1][j]==true) ))
						{
							dp[i][j]=true;
						}

					}	
					else if((p[j-1]==s[i-1] or p[j-1]=='.') and dp[i-1][j-1]){
							dp[i][j]=true;
					}


				}
				
			}
			flag=dp[slen][plen];
			for (int i = 0; i < slen+1; ++i)
			{
				delete [] dp[i];
			}
			delete [] dp;
			return flag;
	}		
	
};

int main()
 {
 	string s="aaa";
 	string p="ab*a*c*a";
 	Solution solution;
 	bool result=solution.isMatch(s,p);
 	if(result)
 		cout<<"True"<<endl;
 	else
 		cout<<"False"<<endl;

 }