#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x),next(NULL){}
	
};
class Solution{
public:
	ListNode* reverseList(ListNode *head){
		if(head==NULL) return head;
		if(head->next==NULL) return head;
		//construct a head node h 
		ListNode* h=new ListNode(0);
		ListNode *p=head;
		ListNode *q=p->next;
		while(q!=NULL){
			p->next=h->next;			
			h->next=p;
			p=q;
			q=q->next;	
		}
		p->next=h->next;
		h->next=p;
		return h->next;
	}
};



int main()
{

	ListNode *head=new ListNode(0);
	ListNode *p=head;
	for (int i = 0; i < 10; ++i)
	{
		p->next=new ListNode(i);
		p=p->next;
	}
	Solution solution;
	ListNode *result=solution.reverseList(head);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;	
	}
	/* code */
	return 0;
}