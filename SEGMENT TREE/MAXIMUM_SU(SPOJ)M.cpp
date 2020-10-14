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
vector<int> a(N);
vector<pr> seg(4*N);

pr merge(pr a,pr b)
{
	pr c;
	if(a.fi>=b.fi)
		c={a.fi,max(a.se,b.fi)};
	else
		c={b.fi,max(b.se,a.fi)};
	return c;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos].fi=a[l];
		seg[pos].se=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=merge(seg[2*pos+1],seg[2*pos+2]);
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
		seg[pos].fi=v;
		//upd(pos,l,r,v);
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=merge(seg[2*pos+1],seg[2*pos+2]);
}

pr query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return {0,0};
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return merge(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	cin>>n;
	a.resize(n);
	int i,q,x,y;
	char c;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	cin>>q;
	while(q--)
	{
		cin>>c>>x>>y;
		if(c=='Q')
		{
			pr val=query(x-1,y-1);
			cout<<val.fi+val.se<<endl;
		}
		else
			update(x-1,x-1,y);
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