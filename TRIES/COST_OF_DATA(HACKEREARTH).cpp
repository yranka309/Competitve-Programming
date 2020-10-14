#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int ans=0;
#define siz 26
struct trie{
	trie *ch[siz];//childen
	bool isend;
};

trie* getnode()
{
	trie *p=new trie;
	p->isend=false;
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
	}
	temp->isend=true;
}

//code to serach string
/*bool search(trie *root,string s)
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

void calc(trie* root)
{
	if(root==NULL)	return;
	ans++;
	for(int i=0;i<26;i++)
		calc(root->ch[i]);
}

void solve()
{
	int n;
	cin>>n;
	trie* root=getnode();
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		insert(root,s);
	}
	ans=0;
	calc(root);
	cout<<ans<<endl;
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