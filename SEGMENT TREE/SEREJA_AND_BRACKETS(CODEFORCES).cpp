#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 2000005
struct node{
	int val,op,cl;
};
node t[N];
int n;

void build()
{
	for(int i=n-1;i>0;i--)
	{
		int x=min(t[i<<1].op,t[i<<1|1].cl);
		t[i].val=t[i<<1].val+t[i<<1|1].val+x;
		t[i].op=t[i<<1].op+t[i<<1|1].op-x;
		t[i].cl=t[i<<1].cl+t[i<<1|1].cl-x;
	}
}

int query(int l,int r)
{
	node o={0,0,0},c={0,0,0};
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			int x=min(o.op,t[l].cl);
			o.cl+=t[l].cl-x;
			o.op+=t[l].op-x;
			o.val+=t[l].val+x;
			l++;
		}
		if(r&1)
		{
			r--;
			int x=min(c.cl,t[r].op);
			c.cl+=t[r].cl-x;
			c.op+=t[r].op-x;
			c.val+=t[r].val+x;
		}
	}
	return o.val+c.val+min(o.op,c.cl);
}

void solve()
{
	string str;
	cin>>str;
	n=str.length();
	int i,l,r,q;
	memset(t,0,sizeof(t));
	for(i=0;i<n;i++)
	{
		if(str[i]=='(')
			t[i+n].op=1;
		else
			t[i+n].cl=1;
	}
	build();
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<2*query(l-1,r)<<endl;
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