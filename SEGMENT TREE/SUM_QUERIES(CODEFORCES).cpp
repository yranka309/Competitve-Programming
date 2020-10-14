#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 200005
int n;
vector<int> a(N);

struct node{
	pr ar[10];
};

vector<node> seg(4*N);

node assign(int val)
{
	node c;
	int i,z=val;
	for(i=0;i<10;i++)
	{
		int x=val%10;
		if(x)
			c.ar[i]={z,1e18};
		else
			c.ar[i]={1e18,1e18};
		val/=10;
	}
	return c;
}

node combine(node a,node b)
{
	node c;
	for(int i=0;i<10;i++)
	{
		if(a.ar[i].fi<b.ar[i].fi)
		{
			c.ar[i]={a.ar[i].fi,min(a.ar[i].se,b.ar[i].fi)};
		}
		else
		{
			c.ar[i]={b.ar[i].fi,min(b.ar[i].se,a.ar[i].fi)};
		}
	}
	return c;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=assign(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=combine(seg[2*pos+1],seg[2*pos+2]);
}

/*
// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=(r-l+1)*x;
}

// PART OF LAZY PROPAGATION
void shift(int pos,int l,int r)
{
	int mid=(l+r)/2;
	upd(2*pos+1,l,mid,lazy[pos]);
	upd(2*pos+2,mid+1,r,lazy[pos]);
	lazy[pos]=0;
}
*/

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		//upd(pos,l,r,v);
		seg[pos]=assign(v);
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=combine(seg[2*pos+1],seg[2*pos+2]);
}

node query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return assign((int)0);
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return combine(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	int m,i,x,y,z;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	while(m--)
	{
		cin>>x>>y>>z;
		if(x==2)
		{
			node x=query(y-1,z-1);
			int val=1e18;
			for(i=0;i<10;i++)
				val=min(x.ar[i].fi+x.ar[i].se,val);
			if(val==1e18)
				cout<<"-1"<<endl;
			else
				cout<<val<<endl;
		}
		else
		{
			update(y-1,y-1,z);
		}
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