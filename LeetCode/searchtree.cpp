#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
	
};
struct Data{
	int head;
	int tail;
	TreeNode *pointer;
	Data(int x,int y,TreeNode *z) : head(x),tail(y),pointer(z) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if (nums.size()==0)
    	{
    		return NULL;
    	}
    	queue <Data> q;
    	TreeNode *root=new TreeNode((nums.size()-1)/2);
    	Data droot(0,nums.size()-1,root);
    	//q.push(droot);
    	//TreeNode *pointer=root;
    	while(!q.empty()){
    		Data temp=q.front();
    		q.pop();
    		if(temp.head<=(temp.head+temp.tail)/2-1)
    			temp.pointer->left=new TreeNode(nums[(temp.head+((temp.head+temp.tail)/2-1))/2]);
    			q.push(Data(temp.head,(temp.head+temp.tail)/2-1,temp.pointer->left));
    		if((temp.head+temp.tail)/2+1<=temp.tail)
				temp.pointer->left=new TreeNode(nums[(temp.head+((temp.head+temp.tail)/2-1))/2]);
    			q.push(Data((temp.head+temp.tail)/2+1,temp.tail,temp.pointer->right));
    	}

    	return root;

        
    }
};

void printTree(TreeNode *pointer){
	if(pointer!=NULL) cout<<pointer->value<<endl;
		else
			return;
	printTree(pointer->left);
	printTree(pointer->right);
}

int main(int argc, char const *argv[])
{
	//vector<int> v={1,2,3,4};
	int tmp[] = { 0,1, 2, 3,4,5 };
	vector<int> v( tmp, tmp+6); 
	Solution solution;
	//cout<<v.size()<<endl;
	TreeNode *result=solution.sortedArrayToBST(v);
	printTree(result);


	return 0;
}