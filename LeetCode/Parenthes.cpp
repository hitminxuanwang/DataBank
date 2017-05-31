#include <iostream>
#include <stack>
using namespace std;

class Solution{
	public:
		bool isValid(string s){
			stack<char> st;
			for (int i = 0; i < s.length(); ++i)
			{
				if(s[i]=='(' | s[i]=='[' | s[i]=='{')
					st.push(s[i]);
				else{
					if(s[i]==')'){
						if(st.empty()) return 0;
						char tmp=st.top();
						st.pop();
						if(tmp!='(') return 0;
					}
					if(s[i]==']'){
						if(st.empty()) return 0;
						char tmp=st.top();
						st.pop();
						if(tmp!='[') return 0;
					}
					if(s[i]=='}'){
						if(st.empty()) return 0;
						char tmp=st.top();
						st.pop();
						if(tmp!='{') return 0;
					}

				}

			}
			if(st.empty()) return 1;
		}
};


int main(){
	Solution solution;
	string s="({[]})";
	bool result=solution.isValid(s); 
	cout<<result<<endl;
	return 0;
}
