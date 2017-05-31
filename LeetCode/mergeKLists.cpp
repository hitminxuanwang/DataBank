#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x),next(NULL){}
};


class Solution
{
public:
	ListNode* mergeKList(vector<ListNode*>& lists){
		ListNode *list;ListNode* p=list;
		vector<pair<int,int>> nodes;
		for (int i = 0; i < lists.size(); ++i)
		{
			if (lists[i]!=NULL)
			{
				nodes.push_back(pair<int,int>(i,lists[i]->val));
			}
		}
		if (nodes.size()==0)
		{
			return list;
		}
		else{

			int min_index=find_min_value(nodes);
			p->next=new ListNode(lists[min_index]);
			p=p->next;
		}


		return list;
	}
	void find_min_value(vector<pair<int,int>> nodes){

	}


/*ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = (int)lists.size();
    if(k==0) return NULL;
    if(k==1) return lists[0];
    return doMerge(lists, 0, (int)lists.size()-1);
}


ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
    if(left==right) return lists[left];
    else if(left+1==right) return merge2Lists(lists[left], lists[right]);
    ListNode* l1 = doMerge(lists, left, (left+right)/2);
    ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
    return merge2Lists(l1, l2);
}


ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if(l1==l2) return l1;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val>l2->val) return merge2Lists(l2, l1);
    ListNode* newl2 = new ListNode(0); newl2->next = l2;
    ListNode* p1 = l1;
    while (p1->next && newl2->next) {
        if (p1->next->val<newl2->next->val) {
            p1 = p1->next;
        } else {
            ListNode* temp = p1->next;
            p1->next = newl2->next;
            newl2->next = newl2->next->next;
            p1->next->next = temp;
            p1 = p1->next;
        }
    }
    if(!p1->next) p1->next = newl2->next;
    delete newl2;
    return l1;
}*/
	
};

int main()
{
	Solution solution;
	vector<ListNode *> lists;
	for (int j = 0; j < 4; ++j)
	{

		ListNode * list=new ListNode(0);
		ListNode *pointer=list;
		for (int i = 1; i < 3; ++i)
		{
			pointer->next=new ListNode(i+2*j);
			pointer=pointer->next;
		}

		lists.push_back(list);

/*		for (int i = 0; i < 3; ++i)
		{
			cout<<list->val;
			list=list->next;
		}*/
	}
	//cout<<lists.size();
	ListNode* res= solution.mergeKLists(lists);


	while(res)
	{
		cout<<res->val<<endl;
		res=res->next;
	}


	return 0;
}