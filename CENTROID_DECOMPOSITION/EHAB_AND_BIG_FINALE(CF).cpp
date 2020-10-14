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
int ln = 20; 

vector<int> g[N],ans;
int par[N],sub[N],lvl[N];
vector<bool> marked;
int n,level;

// -------- Pre-Processing --------------


void dfs0(int u,int p)
{
	par[u]=p;
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

int askd(int d)
{
	int val;
	cout<<"d "<<d+1<<endl;
	cin>>val;
	return val;
}
 
int asks(int d)
{
	int val;
	cout<<"s "<<d+1<<endl;
	cin>>val;
	return val-1;
}
 
void print(int x)
{
	cout<<"! "<<x+1<<endl;
	return;
}

// --------------Decompostion Part--------

int nn;
void dfs1(int u,int p)//Calculate the size of subtree
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

int dfs2(int u,int p)//return centroid
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

void decompose(int u)
{
	dfs1(u,u);
	nn=sub[u];
	int centroid=dfs2(u,u);
	int dist=askd(centroid);
	if(dist==0)
	{
		print(centroid);
		return;
	}
	marked[centroid]=true;
	if(dist==(level-lvl[centroid]))
		decompose(asks(centroid));
	else
		decompose(par[centroid]);
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
	preprocess();
	level=askd(0);
	decompose(0);
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}