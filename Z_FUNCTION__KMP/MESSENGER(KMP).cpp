#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 500005
int lps[N];

void longestPrefixSuffix(vector<pair<int,char> > &v)
{
	int n=v.size(),i,len=0;
	lps[0]=0,i=1;
	while(i<n)
	{
		if(v[i]==v[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
				lps[i++]=len;
		}
	}
}

void compress(vector<pair<int,char> > &a,int &n)
{
	int m=1,i;
	for(i=1;i<n;i++)
	{
		if(a[i].se==a[m-1].se)
			a[m-1].fi+=a[i].fi;
		else
			a[m++]=a[i];
	}
	n=m;
	a.resize(m);
}
 
void solve()
{
	int n,m,i,ans=0;
	cin>>n>>m;
	vector<pair<int,char> > a(n),b(m);
	char c;
	for(i=0;i<n;i++)
		cin>>a[i].fi>>c>>a[i].se;
	for(i=0;i<m;i++)
		cin>>b[i].fi>>c>>b[i].se;
	
	compress(a,n);
	compress(b,m);
	
	//for(i=0;i<a.size();i++)
	//	cout<<a[i].fi<<" "<<a[i].se<<endl;
	
	if(m==1)
	{
		for(i=0;i<a.size();i++)
			if(a[i].se==b[0].se)
				ans+=max(0ll,a[i].fi-b[0].fi+1);
		cout<<ans<<endl;
		return;
	}
	if(m==2)
	{
		for(i=1;i<a.size();i++)
			if(a[i].se==b[1].se && a[i-1].se==b[0].se)
				ans+=(a[i].fi>=b[1].fi & a[i-1].fi>=b[0].fi);
		cout<<ans<<endl;
		return;
	}
	vector<pair<int,char> > v;
	for(i=1;i<m-1;i++)
		v.pb(b[i]);
	v.pb({0,'*'});
	for(i=0;i<n;i++)
		v.pb(a[i]);
	longestPrefixSuffix(v);
	//for(i=0;i<v.size();i++)
	//	cout<<lps[i]<<" ";
	//cout<<endl;
	
	for(i=m;i<v.size()-1;i++)
	{
		if(lps[i]==m-2)
		{
			int y=i-m+2;
			int x=y-m+1;
			//cout<<i<<" "<<x<<" "<<y<<endl;
			if(a[x].fi>=b[0].fi && a[x].se==b[0].se && a[y].fi>=b[m-1].fi && a[y].se==b[m-1].se)
				ans++;
		}
	}
	cout<<ans<<endl;
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