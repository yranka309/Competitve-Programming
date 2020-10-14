#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

#define siz 2
int max_level=31;
struct trie{
	trie *ch[siz];//childen
};

trie* getnode()
{
	trie *p=new trie;
	for(int i=0;i<siz;i++)
		p->ch[i]=NULL;
	return p;
}

int calc(int a,int level)
{
	return (a>>level)&1;
}

//code to insert the string
void insert(trie *root,int value)
{
	trie *temp=root;
	for(int i=max_level;i>=0;i--)
	{
		int idx=calc(value,i);
		if(temp->ch[idx]==NULL)
			temp->ch[idx]=getnode();
		temp=temp->ch[idx];
	}
}

int ans(trie *root,int value)
{
	int result=0;
	trie* temp=root;
	for(int i=max_level;i>=0;i--)
	{
		if(temp==NULL)	break;
		int bit=calc(value,i);
		if(temp->ch[bit]==NULL)
		{
			result+=(1<<i);
			temp=temp->ch[!bit];
		}
		else	temp=temp->ch[bit];
	}
	return result;
}

void solve()
{
	int q,a,b,val=0;
	cin>>q;
	trie* root=getnode();
	insert(root,0);
	while(q--)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b;
			b=val^b;
			insert(root,b);
		}
		else if(a==2)
		{
			cin>>b;
			val^=b;
		}
		else
			cout<<ans(root,val)<<endl;
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