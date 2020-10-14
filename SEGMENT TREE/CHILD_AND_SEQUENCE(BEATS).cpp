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

struct node{
	int val,mx;
};

int n;
vector<int> a(N);
vector<node> seg(4*N);

node assign(node a,node b)
{
	node c;
	c.mx=max(a.mx,b.mx);
	c.val=a.val+b.val;
	return c;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]={a[l],a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(l==r)
	{
		seg[pos]={v,v};
		return;
	}
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

void update1(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l || seg[pos].mx<v)
		return;
	if(l==r)
	{
		int pp=seg[pos].val;
		seg[pos]={pp%v,pp%v};
		return;
	}
	int mid=(l+r)/2;
	update1(x,y,v,2*pos+1,l,mid);
	update1(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

node query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return {0,0};
	if(x<=l && y>=r)
		return seg[pos];
	int mid=(l+r)/2;
	return assign(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	int q,i,x,y,z,w;
	cin>>n>>q;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	
	while(q--)
	{
		cin>>x>>y>>z;
		if(x==1)
		{
			cout<<query(y-1,z-1).val<<endl;
		}
		else if(x==2)
		{
			cin>>w;
			update1(y-1,z-1,w);
		}
		else
		{
			update(y-1,y-1,z);
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