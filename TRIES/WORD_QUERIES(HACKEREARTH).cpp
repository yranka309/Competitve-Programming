#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

#define siz 26
struct trie{
	trie *ch[siz];//childen
	int sum;
};

trie* getnode()
{
	trie *p=new trie;
	p->sum=0;
	for(int i=0;i<siz;i++)
		p->ch[i]=NULL;
	return p;
}

int calc(char a)
{
	return a-'a';
}

//code to insert the string
void insert(trie *root,string s)
{
	trie *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=calc(s[i]);
		if(temp->ch[idx]==NULL)
			temp->ch[idx]=getnode();
		temp=temp->ch[idx];
		temp->sum++;
	}
}

//code to serach string
int search(trie *root,string s)
{
	trie *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=calc(s[i]);
		if(temp->ch[idx]==NULL)
			return false;
		temp=temp->ch[idx];
	}
	if(temp==NULL)	return 0;
	return temp->sum;
}

/*
//to check whether node have childen or not
bool isempty(trie *root)
{
	for(int i=0;i<siz;i++)
		if(root->ch[i])
			return false;
	return true;
}

//code to delete string s from trie
trie* remove(trie* root,string s,int depth=0)
{
	if(root==NULL)
		return root;
	if(depth==s.size())
	{
		if(root->isend)
			root->isend=false;
		if(isempty(root))
		{
			delete(root);
			root=NULL;
		}
		return root;
	}
	int idx=calc(s[depth]);
	root->ch[idx]=remove(root->ch[idx],s,depth+1);
	if(isempty(root) && root->isend==false)
	{
		delete(root);
		root=NULL;
	}
	return root;
}*/



void solve()
{
	int n,q;
	cin>>n>>q;
	trie *root =getnode();
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		insert(root,s);
	}
	while(q--)
	{
		cin>>s;
		cout<<search(root,s)<<endl;
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}