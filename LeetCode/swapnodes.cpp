#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x):val(x),next(NULL){}
	
};


class Solution{
public:
	ListNode* swapPairs(ListNode *head){
		if (head==NULL)	 return head;
		if(head->next==NULL) return head;
	    ListNode *pre=new ListNode(0);
		pre->next=head;
		head=pre;

		ListNode *p=pre->next;
		ListNode *q=p->next;
		//ListNode *r=q->next;

		while(q!=NULL){
			p->next=q->next;
			q->next=p;
			pre->next=q;
			pre=p;
			if(p==NULL || p->next==NULL) break;
			pre=p;
			p=p->next;
			q=p->next;
		}	
		return head->next;
	}
};



int main()
{

	ListNode * head=new ListNode(1);
	ListNode * p=head;
	for (int i = 2; i < 5; ++i)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution solution;
	ListNode * result=solution.swapPairs(head);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;
	}

	return 0;
}