#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int mul(int a,int b,int m=mod){	return (a*b)%m;}

void z_func(string s,vector<int> &z)
{
	int n=s.size(),i,l=0,r=0;
	z.resize(n,0);
	for(i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && s[r-l]==s[r])
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
				while(r<n && s[r-l]==s[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}

void solve()
{
	int m,k;
	cin>>m>>k;
	string s;
	cin>>s;
	vector<int> z;
	z_func(s,z);
	
	int a[k],i,ans=1,n=s.length(),b[m+2];
	memset(b,0,sizeof(b));
	for(i=0;i<k;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		b[a[i]+n]--;
		if(i)
		{
			int x=a[i]-a[i-1];
			if(x<n && (z[x]+x)!=n)
				ans=0;
		}
	}
	
	for(i=1;i<=m;i++)
	{
		b[i]+=b[i-1];
		if(!b[i])
			ans=mul(ans,26);
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