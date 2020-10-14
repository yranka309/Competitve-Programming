#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;


void solve()
{
	string s;
	cin>>s;
	s+='$';
	int n=s.length(),i;
	vector<pair<char,int > > c;
	vector<int> p(n);
	
	for(i=0;i<n;i++)
		c.pb({s[i],i});
	
	sort(c.begin(),c.end());
	
	p[c[0].se]=0;
	for(i=1;i<n;i++)
	{
		p[c[i].se]=p[c[i-1].se];
		if(c[i-1].fi!=c[i].fi)
			p[c[i].se]++;
	}
	
	int k=0;
	vector<pair< pair<int,int> ,int> > v;
	while((1<<k)<n)
	{
		v.clear();
		for(i=0;i<n;i++)
			v.pb({{p[i],p[(i+(1<<k))%n]},i});
		sort(v.begin(),v.end());
		
		p[v[0].se]=0;
		for(i=1;i<n;i++)
		{
			p[v[i].se]=p[v[i-1].se];
			if(v[i].fi.fi!=v[i-1].fi.fi || v[i].fi.se!=v[i-1].fi.se)
				p[v[i].se]++;
		}
		
		k++;
	}
	
	for(i=0;i<n;i++)
		cout<<v[i].se<<" ";
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}