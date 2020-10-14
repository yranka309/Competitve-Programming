#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* next;
	node(int val)
	{
		this->val=val;
		this->next=NULL;
	}
};

bool isPalindromeUtil(struct node** left, struct node* right) 
{
    if (right == NULL) 
        return true; 
    if(!isPalindromeUtil(left, right->next))//note in double pointers also 
    							// left is written not (*left).
        return false; 
    bool isp1 = (right->data == (*left)->data); 
    *left = (*left)->next; 
  
    return isp1; 
}

ListNode* reverse_iterative(ListNode** head)
{
    ListNode *cur=(*head),*prev=NULL,*next;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
    
ListNode* reverse_recursive(ListNode* temp)
{
    if(temp==NULL || temp->next==NULL)
        return temp;
    ListNode* head=reverse_recursive(temp->next);
    temp->next->next=temp;
    temp->next=NULL;
    return head;
}

int main()
{
	//node* temp=new node(0);
	node* t1,*temp=(node*)malloc(sizeof(node));
	
	//free(temp) - > to delete temp;
}