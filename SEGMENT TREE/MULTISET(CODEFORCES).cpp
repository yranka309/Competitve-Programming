#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 1000005
int n;
vector<int> a(N,0),seg(4*N);

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
	seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		seg[pos]+=v;
		return;
	}
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=(seg[2*pos+1]+seg[2*pos+2]);
}

int query(int x,int pos=0,int l=0,int r=n-1)
{
	if(l==r)	return l;
	int mid=(l+r)/2;
	if(seg[2*pos+1]>=x)
		return query(x,2*pos+1,l,mid);
	else
		return query(x-seg[2*pos+1],2*pos+2,mid+1,r);
}

void solve()
{
	int q,i,x;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a[x-1]++;
	}
	build();
	while(q--)
	{
		cin>>x;
		if(x<0)
		{
			int idx=query(abs(x));
			update(idx,idx,-1);
		}
		else
			update(x-1,x-1,1);
	}
	if(!seg[0])	cout<<"0"<<endl;
	else		cout<<query(1)+1<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);	cout.tie(NULL);
   	solve();
	return 0;
}