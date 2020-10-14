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
vector<int> a(N),seg(4*N);
int lazy[4*N][2];
int b[N],lvl[N],st_time[N],end_time[N],T=0;
vector<int> g[N];

int assign(int a,int b)
{
	return a+b;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=b[a[l]];
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

int node_level(int i)
{
	int x=a[i];
	return lvl[x];
}

// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x,int y)
{
	lazy[pos][0]+=x;
	lazy[pos][1]+=y;
	
	if(l==r)
	{
		int ll=node_level(l);
		if(ll)
			seg[pos]+=y-x;
		else
			seg[pos]+=x-y;
		//cout<<"l is "<<l<<" "<<seg[pos]<<" "<<lazy[pos][0]<<" "<<lazy[pos][1]<<endl;
	}
}

// PART OF LAZY PROPAGATION
void shift(int pos,int l,int r)
{
	int mid=(l+r)/2;
	upd(2*pos+1,l,mid,lazy[pos][0],lazy[pos][1]);
	upd(2*pos+2,mid+1,r,lazy[pos][0],lazy[pos][1]);
	lazy[pos][0]=lazy[pos][1]=0;
}

void update(int x,int y,int v1,int v2,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		upd(pos,l,r,v1,v2);
		return;
	}
	shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v1,v2,2*pos+1,l,mid);
	update(x,y,v1,v2,2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	shift(pos,l,r);
	int mid=(l+r)/2;
	return assign(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void dfs(int u,int p)
{
	lvl[u]=1-lvl[p];
	a[T]=u;
	st_time[u]=T++;
	
	for(auto v:g[u])
	{
		if(v==p)
			continue;
		dfs(v,u);
	}
	end_time[u]=T;
}

void solve()
{
	int m,i,x,y,z;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	lvl[0]=0;
	dfs(0,0);
	build();
	while(m--)
	{
		cin>>x>>y;
		y--;
		if(x==1)
		{
			cin>>z;
			int l=st_time[y];
			int r=end_time[y]-1;
			int level=lvl[y];
			if(level)
				update(l,r,0,z);
			else
				update(l,r,z,0);
		}
		else
		{
			int val=st_time[y];
			cout<<query(val,val)<<endl;
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}