#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100005
int ln = 20; 

vector<int> g[N];
int par[N],dp[22][N],sub[N],lvl[N];
vector<char> ans;
vector<bool> marked;
bool flag=true;
int n;

/*
// ----------LCA and distance----------

int lca(int u,int v)
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

int dist(int u,int v)
{
	return lvl[u]+lvl[v]-2*lvl[lca(u,v)];
}
*/

// -------- Pre-Processing --------------


void dfs0(int u,int p)
{
	dp[0][u]=p;
	for(int i=1;i<ln;i++)
		dp[i][u]=dp[i-1][dp[i-1][u]];
	for(auto v:g[u])
	{
		if(v==p)
			continue;
		lvl[v]=lvl[u]+1;
		dfs0(v,u);
	}
}

void preprocess()//0 indexing
{
	lvl[0]=0;
	dfs0(0,0);
}



// --------------Decompostion Part--------

int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	for(auto v:g[u])
	{
		if(v==p || marked[v])
			continue;
		dfs1(v,u);
		sub[u]+=sub[v];
	}
}

int dfs2(int u,int p)
{
	for(auto v:g[u])
	{
		if(v==p || marked[v])
			continue;
		if(sub[v]>nn/2)
			return dfs2(v,u);
	}
	return u;
}

void decompose(int u,int p,char c)
{
	dfs1(u,u);
	nn=sub[u];
	if(c>'Z')
		flag=false;
	int centroid=dfs2(u,u);
	//if(p==-1)
	//	p=centroid;
	//par[centroid]=p;
	ans[centroid]=c;
	marked[centroid]=true;
	for(auto v:g[centroid])
	{
		if(!marked[v])
		decompose(v,centroid,c+1);
	}
}

void assign()
{
	marked.resize(n,false);
	ans.resize(n);
}

void solve()
{
	int i,a,b;
	cin>>n;
	assign();
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		g[a-1].pb(b-1);
		g[b-1].pb(a-1);
	}
	decompose(0,-1,'A');
	if(!flag)
	{
		cout<<"Impossible!"<<endl;
		return;
	}
	for(auto x:ans)
		cout<<x<<" ";cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}