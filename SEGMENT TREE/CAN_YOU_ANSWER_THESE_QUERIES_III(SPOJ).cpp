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
int n,m=-1e9,a[N];

struct node{
	int sum,bestrightsum,bestleftsum,bestsum;
};
node seg[N];

void assign(node &a,int val)
{
	a.sum=a.bestsum=a.bestrightsum=a.bestleftsum=val;
}

node merge(node A,node B)
{
	node c;
	c.sum=A.sum+B.sum;
	c.bestleftsum=max(A.bestleftsum,A.sum+B.bestleftsum);
	c.bestrightsum=max(A.bestrightsum+B.sum,B.bestrightsum);
	c.bestsum=max(max(A.bestsum,B.bestsum),A.bestrightsum+B.bestleftsum);
	return c;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		assign(seg[pos],a[l]);
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
		//upd(pos,l,r,v);
		assign(seg[pos],v);
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=merge(seg[2*pos+1],seg[2*pos+2]);
}

node query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return {m,m,m,m};
	if(x<=l && y>=r)
	{
		return seg[pos];
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return merge(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	int q,x,y,z;
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>z;
		if(x==1)
		{
			node ans=query(y-1,z-1);
			cout<<ans.bestsum<<endl;
		}
		else
			update(y-1,y-1,z);
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