#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution
{
public:
	ListNode* inverseList(ListNode *head,ListNode *post){
		if(head==NULL) return head;
		if(head->next==NULL) return head;
		//construct a head node h 
		ListNode* h=new ListNode(0);
		h->next=post;
		ListNode *p=head;
		ListNode *q=p->next;
		while(q!=post){
			p->next=h->next;			
			h->next=p;
			p=q;
			q=q->next;	
		}
		p->next=h->next;
		h->next=p;
		return h->next;
	}

	ListNode * reverseKGroup(ListNode * head,int k){
		if (head==NULL) return head;
		ListNode *h=head; // to store the final head pointer
		while(1){
			ListNode *post=head;
			for (int i = 0; i < k; ++i)
			{
				if (post==NULL) return h;
				post=post->next;
			}
			head=inverseList(head,post);
			
			}
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
	ListNode *result=solution.reverseKGroup(head,3);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;	
	}
	return 0;
}