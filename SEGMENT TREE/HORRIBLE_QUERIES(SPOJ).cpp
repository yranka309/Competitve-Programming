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
vector<int> a(N),seg(4*N),lazy(4*N);

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		lazy[pos]=seg[pos]=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
	lazy[pos]=seg[pos];
}

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

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		upd(pos,l,r,v);
		return;
	}
	shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	shift(pos,l,r);
	int mid=(l+r)/2;
	return (query(x,y,2*pos+1,l,mid)+query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	int c,x,y,z,w;
	cin>>n>>c;
	build();
	while(c--)
	{
		cin>>x>>y>>z;
		if(x)
			cout<<query(y-1,z-1)<<endl;
		else
		{
			cin>>w;
			update(y-1,z-1,w);
		}
	}
	lazy.clear();
	seg.clear();
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