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
int add(int a,int b,int m=mod){	return (a+b)%m;}
int sub(int a,int b,int m=mod){	return (a-b+m)%m;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
// x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;

#define N 300005
int timer=1;
vector<int> g[N];
int dp[22][N],ln=log2(N),lvl[N];
int tin[N],tout[N];

void dfs(int u,int par,int l=0)
{
	tin[u]=timer++;
	dp[0][u]=par;
	lvl[u]=l;
	for(int i=1;i<=ln;i++)
		dp[i][u]=dp[i-1][dp[i-1][u]];
	for(auto v:g[u])
	{
		if(v==par)	continue;
		dfs(v,u,l+1);
	}
	tout[u]=timer++;
}

int LCA(int u,int v)
{
	if(lvl[u]>lvl[v])
		swap(u,v);
	int i;
	for(i=ln;i>=0;i--)
	{
		if(lvl[u]<=(lvl[v]-(1<<i)))
			v=dp[i][v];
	}
	if(u==v)	return u;
	for(i=ln;i>=0;i--)
		if(dp[i][u]!=dp[i][v])
		{
			u=dp[i][u];
			v=dp[i][v];
		}
	return dp[0][u];
}

int distance(int a,int d)
{
	int i;
	int ans=a;
	for(i=ln;i>=0;i--)
	{
		int x=(1<<i);
		if(d&x)
			ans=dp[i][ans];
	}
	return ans;
}

void solve()
{
	int n,i,a,b,c,x,y,q;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,1);
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		int lca=LCA(a,b);
		
		int dist=lvl[a]+lvl[b]-2*lvl[lca];
		if(dist<=c)
		{
			cout<<b<<endl;
			continue;
		}
		else
		{
			int val1=lvl[a]-lvl[lca];
			int val2=lvl[b]-lvl[lca];
			if(val1>=c)
				cout<<distance(a,c)<<endl;
			else
				cout<<distance(b,val1+val2-c)<<endl;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}