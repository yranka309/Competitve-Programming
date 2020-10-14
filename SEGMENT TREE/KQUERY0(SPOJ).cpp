#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 30005
int n;
vector<int> a(N);
vector<int> seg[4*N];

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos].push_back(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	merge(seg[2*pos+1].begin(),seg[2*pos+1].end(),seg[2*pos+2].begin(),seg[2*pos+2].end(),back_inserter(seg[pos]));
	/*cout<<"pos is  "<<pos<<endl;
	for(int i=0;i<seg[pos].size();i++)
		cout<<seg[pos][i]<<" ";
	cout<<endl;*/
}

/*
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
*/

int query(int x,int y,int k,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos].size()-(upper_bound(seg[pos].begin(),seg[pos].end(),k)-seg[pos].begin());
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return (query(x,y,k,2*pos+1,l,mid)+query(x,y,k,2*pos+2,mid+1,r));
}

void solve()
{
	cin>>n;
	a.resize(n);
	int i,q,x,y,z,val=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>z;
		x=val^x;
		y=val^y;
		z=val^z;
		if(x<1)	x=1;
		if(y>n)	y=n;
		//cout<<"x y z are  "<<x<<" "<<y<<" "<<z<<endl;
		val=query(x-1,y-1,z);
		cout<<val<<endl;
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