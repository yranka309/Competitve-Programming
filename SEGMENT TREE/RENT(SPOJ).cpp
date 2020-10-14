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

struct plane{
	int st,en,p;
};

vector<plane> a(N);
vector<int> seg(4*N);
int n;

/*void build(int pos,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

void upd(int pos,int l int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=(r-l+1)*x;
}

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
		//cout<<"updated"<<endl;
		//upd(pos,l,r,v);
		seg[pos]=v;
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return 	max(query(x,y,2*pos+1,l,mid), query(x,y,2*pos+2,mid+1,r));
}

bool comp(plane a,plane b)
{
	return a.en<b.en;
}

void solve()
{
	cin>>n;
	int i;
	a.resize(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i].st>>a[i].en>>a[i].p;
		a[i].en+=a[i].st;
	}
	sort(a.begin(),a.end(),comp);
	for(i=0;i<n;i++)
	{
		int val1=query(0,a[i].st,(int)0,(int)0,N);
		int val2=query(0,a[i].en,(int)0,(int)0,N);
		//cout<<val1<<" "<<val2<<endl;
		if(val1+a[i].p>val2)
		{
			//cout<<val1+a[i].p<<endl;
			update(a[i].en,a[i].en,val1+a[i].p,(int)0,(int)0,N);
		}
	}
	cout<<query(0,a[n-1].en,(int)0,(int)0,N)<<endl;
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