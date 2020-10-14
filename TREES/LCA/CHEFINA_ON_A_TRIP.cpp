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

#define N 100005
vector<int> g[N];
int n,queries,inc[N],desc[N],dp[22][N];
int ln,lvl[N],a[N];

void clr(int n)
{
	for(int i=0;i<=n;i++)
		g[i].clear();
	ln=log2(n)+1;
}

void dfs(int u,int par)
{
	int i;
	for(i=1;i<=ln;i++)
		dp[i][u]=dp[i-1][dp[i-1][u]];
	
	inc[u]=u;
	desc[u]=u;
	//cout<<"u and par are "<<u<<" "<<par<<" "<<a[u]<<" "<<a[par]<<endl;
	if(a[par]>a[u])	inc[u]=inc[par];
	if(a[par]<a[u])	desc[u]=desc[par];
	
	for(auto v:g[u])
	{
		if(v==par)	continue;
		lvl[v]=lvl[u]+1;
		dp[0][v]=u;
		dfs(v,u);
	}
}

int lca(int u,int v)
{
	if(lvl[u]>lvl[v])
		swap(u,v);
	int i;
	for(int i=ln;i>=0;i--)
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

void solve()
{
	cin>>n>>queries;
	clr(n);
	
	int x,y,z,i;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
		
	lvl[1]=1;
	dp[0][1]=1;
	dfs(1,1);
	
	for(i=0;i<queries;i++)
	{
		cin>>x>>y;
		z=lca(x,y);
		if(inc[x]==inc[y])	cout<<1;
		else if(desc[x]==desc[y] && (z==x || z==y))	cout<<1;
		else
		{
			int p=inc[x];
			int q=inc[y];
			int r=inc[z];
			if(p==r && desc[inc[y]]==desc[z])		cout<<1;
			else if(q==r && desc[inc[x]]==desc[z])	cout<<1;
			else		cout<<0;
		}
		
	}
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;cin>>t;
	while(t--)	solve();
	return 0;
}

If an element was not initially in map and if asked mp[a],the element gets inserted 
a%=mod take a lot of time... try to use it minimum and use memset as it reduces a lot of time usage
// use if(a>=mod) a%=mod 