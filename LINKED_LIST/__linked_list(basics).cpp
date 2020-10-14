#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *next;
};

void Print(Node* head)
{
	while(head)
	{
		cout<<head->val<< " ";
		head=head->next;
	}
}

void addNode(Node** head,int val)
{
	//Node* temp=(Node* )malloc(sizeof(Node));
	Node* temp=new Node();
	temp->val=val;
	temp->next=(*head);
	(*head)=temp;
}

void solve()
{
	Node* head=NULL;
	int size,a;
	cin>>size;
	
	while(size--)
	{
		cin>>a;
		addNode(&head,a);
	}
	
	Print(head);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}