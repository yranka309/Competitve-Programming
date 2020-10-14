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
int n;
vector<int> a(N),seg(N);
unordered_map<int,int> mp;//Remember to use unordered map
/*void build(int pos=0,int l=0,int r=n-1)
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
}*/

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
		//upd(pos,l,r,v);
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
	int low=0,high=n-1,mid,val,ans=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		val=query(0,mid);
		//cout<<"mid is "<<mid<<"  "<<val<<endl;
		if(val<k)
			low=mid+1;
		else if(val==k)
		{
			ans=mid;
			high=mid-1;
		}
		else
			high=mid-1;
	}
	//cout<<"ans is "<<ans<<endl;
	return ans;
}

void solve()
{
	int q,x,y,i;
	cin>>q;
	char c;
	pair<char,int> b[q];
	set<int> s;
	//cout<<"yes"<<endl;
	for(i=0;i<q;i++)
	{
		cin>>b[i].fi>>b[i].se;
		if(b[i].fi=='I' || b[i].fi=='D')
			s.insert(b[i].se);
	}
	n=s.size(),i=0;
	a.resize(n);
	seg.resize(4*n);
	int value[n];
	memset(value,0,sizeof(value));
	for(auto it=s.begin();it!=s.end();it++)
	{
		a[i++]=*it;
		mp[*it]=i;
	}
	//for(i=0;i<n;i++)
	//	cout<<a[i]<<" "<<mp[a[i]]<<endl;
	
	for(i=0;i<q;i++)
	{
		//cout<<"i is  "<<i<<endl;
		if(b[i].fi=='I')
		{
			int idx=mp[b[i].se]-1;
			if(value[idx])	continue;
			update(idx,idx,1);
			value[idx]=1;
		}
		else if(b[i].fi=='D')
		{
			int idx=mp[b[i].se]-1;
			if(!value[idx])	continue;
			update(idx,idx,0);
			value[idx]=0;
		}
		else if(b[i].fi=='K')
		{
			if(b[i].se>query(0,n-1))
			{
				cout<<"invalid"<<endl;
				continue;
			}
			//cout<<b[i].se<<endl;
			cout<<a[bs(b[i].se)]<<endl;
		}
		else
		{
			int val=lower_bound(a.begin(),a.end(),b[i].se)-a.begin();
			//cout<<"val is "<<val<<" "<<a[val]<<endl;
			cout<<query(0,val-1)<<endl;
		}
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