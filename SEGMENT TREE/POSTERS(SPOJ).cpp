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
/*
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
}*/

// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	if(!x)	return;
	lazy[pos]=x;
	seg[pos]=x;
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
	int i,m;
	cin>>m;
	set<int> s;
	pr q[m];
	for(i=0;i<m;i++)
	{
		cin>>q[i].fi>>q[i].se;
		s.insert(q[i].fi);
		s.insert(q[i].se);
	}
	n=s.size();
	map<int,int> mp;
	i=1;
	for(auto it=s.begin();it!=s.end();it++)
		mp[*it]=i++;
	for(i=0;i<m;i++)
	{
		int l=mp[q[i].fi]-1;
		int r=mp[q[i].se]-1;
		update(l,r,i+1);
	}
	set<int> s1;
	for(i=0;i<n;i++)
		s1.insert(query(i,i));
	cout<<s1.size()<<endl;
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