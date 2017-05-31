#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) :val(x),next(NULL){}
};





class Solution{
public:
	ListNode * merge2Lists(ListNode* l1,ListNode* l2){
 		if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* p=l1;    
        ListNode* q=l2;
        ListNode *head,*tail;
        if(p->val<=q->val)
        {
            head=p;
            p=p->next;    
        }
        else
        {
            head=q;
            q=q->next;
        }
        tail=head;

        while(p && q){
            if(p->val<=q->val)
            {
                tail->next=p;
                tail=tail->next;
                p=p->next;
                
            }
            else
            {
                tail->next=q;
                tail=tail->next;
                q=q->next;
            }
        }
        if(!p)
            tail->next=q;
        if(!q)
          tail->next=p;
        return head;    
    
	}

	ListNode * mergeKLists(vector <ListNode*>& lists){
		if (lists.size()==0) return NULL;
		if(lists.size()==1) return lists[0];
		if (lists.size()==2) return merge2Lists(lists[0],lists[1]);
		//return 
		vector<ListNode *> pre(&lists[0],&lists[lists.size()/2]);
		vector<ListNode *> pro(&lists[lists.size()/2],&lists[lists.size()]);
		return merge2Lists(mergeKLists(pre),mergeKLists(pro));
	 }
};

int main()
{
	ListNode *l1=new ListNode(1);
	ListNode *p=l1;
	for(int i=3;i<10;i=i+2){
		p->next=new ListNode(i);
		p=p->next;
	}

	ListNode *l2=new ListNode(0);
	ListNode *q=l2;
	for (int i =2; i < 10; i=i+2)
	{
		q->next=new ListNode(i);
		q=q->next;
	}
	ListNode *l3=new ListNode(11);
	ListNode *r=l3;
	for (int i =12; i < 20; i=i+2)
	{
		r->next=new ListNode(i);
		r=r->next;
	}	
	vector<ListNode *> lists;
	lists.push_back(l1);
	lists.push_back(l2);
	lists.push_back(l3);
	Solution solution;
	ListNode *result=solution.mergeKLists(lists);
	// while(l1){
	// 	cout<<l1->val<<endl;
	// 	l1=l1->next;
	// }
	while(result){
		cout<<result->val<<endl;
		result=result->next;
	}


	return 0;
}