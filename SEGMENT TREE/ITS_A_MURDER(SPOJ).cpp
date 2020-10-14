#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100005
int n;
vector<pr> a(N);
vector<int> seg(4*N);

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}

/*
// PART OF LAZY PROPAGATION
void upd(int pos,int l int r,int x)
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
		seg[pos]=v;
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return query(x,y,2*pos+1,l,mid)+query(x,y,2*pos+2,mid+1,r);
}

bool comp(pr a,pr b)
{
	if(a.fi==b.fi)
		return a.se>b.se;
	return a.fi<b.fi;
}

void solve()
{
	cin>>n;
	int i,ans=0;
	a.resize(n);
	map<int,int> mp;
	build();
	for(i=0;i<n;i++)
	{
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a.begin(),a.end(),comp);
	for(i=0;i<n;i++)
	{
		ans+=query(0,a[i].se);
		update(a[i].se,a[i].se,a[i].fi);
	}
	cout<<ans<<endl;
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