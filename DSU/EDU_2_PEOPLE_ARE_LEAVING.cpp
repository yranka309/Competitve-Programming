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
int add(int a,int b,int m=mod){	int c=(a+b);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a-b);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;
vector<int> par;
int n;

int parent(int a)
{
	if(a==par[a] || a==-1)
		return a;
	return par[a]=parent(par[a]);
}

update(int a)
{
	if(a==n)
		par[a]=-1;
	else
		par[a]=a+1;
}

void solve()
{
	int m;
	cin>>n>>m;
	int i;
	par.resize(n+1);
	for(i=1;i<=n;i++)	par[i]=i;
	char c;
	int d;
	while(m--)
	{
		cin>>c>>d;
		if(c=='-')
		{	update(d); }
		else
			cout<<parent(d)<<endl;
	}
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}