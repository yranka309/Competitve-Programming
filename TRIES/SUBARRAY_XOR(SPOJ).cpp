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
int max_level=20;
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
		temp->sum++;
	}
}

int summ(trie *root)
{
	if(root==NULL)	return 0;
	return root->sum;
}

int ans(trie *root,int prefix,int value)
{
	int result=0;
	trie* temp=root;
	for(int i=max_level;i>=0;i--)
	{
		if(temp==NULL)	break;
		int bit=calc(value,i);
		int prefixbit=calc(prefix,i);
		if(prefixbit==bit)
		{
			if(prefixbit==1)
				result+=summ(temp->ch[1]);
			temp=temp->ch[0];
		}
		else
		{
			if(prefixbit==0)
				result+=summ(temp->ch[0]);
			temp=temp->ch[1];
		}
	}
	return result;
}

void solve()
{
	int n,k,i;
	cin>>n>>k;
	int data[n+1],prefix[n+1];
	for (i = 1; i <= n; i ++)
		cin >> data[i];
	trie* root = getnode();
	insert(root, 0);
	int result = 0;
	prefix[0]=0;
	for(i = 1; i <= n; i ++)
	{
		prefix[i] = prefix[i - 1] ^ data[i];
		result += ans(root, prefix[i], k);
		insert(root, prefix[i]);
	}
	cout << result << endl;
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