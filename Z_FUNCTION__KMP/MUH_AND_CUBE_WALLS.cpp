#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

void z_func(vector<int> v,vector<int> &z)
{
	int n=v.size(),i,l=0,r=0;
	z.resize(n,0);
	for(i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && v[r-l]==v[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<(r-i+1))	z[i]=z[k];
			else
			{
				l=i;
				while(r<n && v[r-l]==v[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}

void solve()
{
	int n,w;
	cin>>n>>w;
	int a[n],b[w],i,ans=0;
	vector<int> v;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<w;i++)
	{
		cin>>b[i];
		if(i)
			v.pb(b[i]-b[i-1]);
	}
	v.pb(1e10);
	for(i=1;i<n;i++)
		v.pb(a[i]-a[i-1]);
	
	vector<int> z;
	z_func(v,z);
	
	for(i=0;i<z.size();i++)
		if(z[i]==(w-1))
			ans++;
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}