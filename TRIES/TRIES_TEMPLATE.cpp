#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int T=1,k,ans;

#define siz 26
struct trie{
	trie *ch[siz];//childen
	bool isend;
	int val;
};

trie* getnode()
{
	trie *p=new trie;
	p->isend=false;
	p->val=0;
	for(int i=0;i<siz;i++)
		p->ch[i]=NULL;
	return p;
}

int calc(char a)
{
	return a-'A';
}

//code to insert the string
void insert(trie *root,string s)
{
	trie *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=calc(s[i]);
		//cout<<"idx is "<<idx<<endl;
		if(temp->ch[idx]==NULL)
			temp->ch[idx]=getnode();
		temp=temp->ch[idx];
		temp->val++;
	}
	temp->isend=true;
}

void traverse(trie* root)
{
	trie* temp=root;
	ans+=temp->val/k;
	for(int i=0;i<26;i++)
		if(temp->ch[i]!=NULL)
			traverse(temp->ch[i]);
}

/*
//code to serach string
bool search(trie *root,string s)
{
	trie *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=calc(s[i]);
		if(temp->ch[idx]==NULL)
			return false;
		temp=temp->ch[idx];
	}
	return (temp!=NULL && temp->isend);
}

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
	int n,i;
	cin>>n>>k;
	string s;
	trie* root=getnode();
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert(root,s);
	}
	ans=0;
	traverse(root);
	cout<<"Case #"<<T++<<": "<<ans<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}