#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

void z_func(string &s,vector<int> &z)
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
	string s;
	cin>>s;
	vector<int> z;
	z_func(s,z);
	int i,n=s.length();
	int cnt[n+1];
	memset(cnt,0,sizeof(cnt));
	cnt[n]=1;
	set<int> v={n};
	for(i=n-1;i>0;i--)
	{
		cnt[z[i]]++;
		if(i+z[i]==n)
			v.insert(z[i]);
	}
	for(i=n-1;i>=0;i--)
		cnt[i]+=cnt[i+1];
	cout<<v.size()<<endl;
	for(auto x:v)
		cout<<x<<" "<<cnt[x]<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}