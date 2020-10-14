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
string s1,s2;
int ans=0,n;
int v1[N],v2[N];
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

void fun()
{
	string s=s2+'#'+s1;
	vector<int> z;
	int i,m=s2.length();
	
	z_func(s,z);
	for(i=0;i<n;i++)
		v1[i]=z[i+m+1];
	
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	s=s2+'#'+s1;
	z_func(s,z);
	for(i=0;i<n;i++)
		v2[i]=z[n+m-i];
	for(i=n-2;i>=0;i--)
		v2[i]=max(v2[i],v2[i+1]);
		
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	for(i=0;i<n;i++)
	{
		int pos=i+m-1;
		if(v2[pos]>=(m-v1[i]))
		{
			ans++;
			return;
		}
	}
}

void solve()
{
	cin>>s1;
	int t;
	cin>>t;
	n=s1.length();
	while(t--)
	{
		cin>>s2;
		if(s2.length()==1)
			continue;
		fun();
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