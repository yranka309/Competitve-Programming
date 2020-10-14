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
		seg[pos]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}

// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=x;
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
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	shift(pos,l,r);
	int mid=(l+r)/2;
	return min(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	cin>>n;
	int val[n+1],cost[n],pos[n+1],i;
	a=vector<int> (n);
	for(i=1;i<=n;i++)
	{
		cin>>val[i];
		pos[val[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		cin>>cost[i];
		a[i-1]=cost[i];
		if(i>1)
			a[i-1]+=a[i-2];
	}
	build();
	int ans=seg[0];
	for(i=1;i<=n;i++)
	{
		int idx=pos[i];
		if(idx>1)
			update(0,idx-2,cost[idx]);
		if(idx<n)
			update(idx-1,n-1,-cost[idx]);
		ans=min(ans,seg[0]);
		//cout<<seg[0]<<endl;
	}
	cout<<ans<<endl;
	
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}