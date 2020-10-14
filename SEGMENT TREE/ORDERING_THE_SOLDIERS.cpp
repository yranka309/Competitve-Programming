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

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=1;
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
}*/

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
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
	{
		return seg[pos];
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return query(x,y,2*pos+1,l,mid)+query(x,y,2*pos+2,mid+1,r);
}

int bs(int k)
{
	int low=0,high=n-1,mid,ans=0;
	k++;
	while(low<=high)
	{
		mid=(low+high)/2;
		int val=query(mid,n-1);
		if(val==k)
		{
			ans=mid;
			low=mid+1;
		}
		else if(val<k)
			high=mid-1;
		else
			low=mid+1;
	}
	return ans+1;
}

void solve()
{
	cin>>n;
	int i,ans[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	for(i=n-1;i>=0;i--)
	{
		ans[i]=bs(a[i]);
		update(ans[i]-1,ans[i]-1,0);
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
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