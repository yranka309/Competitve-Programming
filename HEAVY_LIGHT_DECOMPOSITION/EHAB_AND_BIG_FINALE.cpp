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

int chainNo,ptr,n,ln,dp[20][N],level;
vector<int> g[N],cost[N],indexx[N];
vector<int> chainHead(N),chainInd(N),otherEnd(N);
vector<int> posInBase(N),lvl(N),sub(N),chainSize(N);
vector<int> baseArray(N);

/*-----------------------------------------Start of LcA--------------------------------------------------*/

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

/*-----------------------------------------End of LcA----------------------------------------------------*/

void dfs(int u,int p,int l=0)
{
	dp[0][u]=p;
	lvl[u]=l;//level of every node
	sub[u]=1;//subarray size
	for(int i=1;i<=ln;i++)
		dp[i][u]=dp[i-1][dp[i-1][u]];
	for(auto v:g[u])
	{
		if(v==p)
			continue;
		dfs(v,u,l+1);
		sub[u]+=sub[v];
	}
}

/* --------------------------------------Heavy Light Secompostion Part ----------------------------------*/

void HLD(int u,int p)
{
	//cout<<"chin No are "<<u<<" "<<chainNo<<endl;
	if(chainHead[chainNo]==-1)
		chainHead[chainNo]=u;// chainHead -> starting node of chain
	chainInd[u]=chainNo;//chainInd -> chain no of node u
	//Position of this node in baseArray which we will use in segTree
	posInBase[u]=ptr;
	baseArray[ptr++]=u;
	chainSize[chainNo]++;
	int sc=-1,i;
	for(auto v:g[u])
	{
		if(v==p)
			continue;
		if(sc==-1 || sub[v]>sub[sc])
			sc=v;
	}
	
	if(sc==-1)
		return;
	HLD(sc,u);
	for(i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==p || v==sc)
			continue;
		chainNo++;
		HLD(g[u][i],u);
	}
}

/*--------------------------------------Dealing with Queries---------------------------------------------*/

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

void query(int u)
{
	int uchain=chainInd[u];
	int size=chainSize[uchain];
	int pos=posInBase[u];
	int lastpos=pos+size-1;
	int val=baseArray[lastpos];
	int dist=askd(val);
	int levely=(-dist+level+lvl[val])/2;
	int node=baseArray[lastpos-(lvl[val]-levely)];
	if(level==lvl[node])
	{
		print(node);
		return;
	}
	int ances=asks(node);
	query(ances);
}

void preprocess()
{
	for(int i=0;i<=n;i++)
	{
		g[i].clear();
		indexx[i].clear();
		cost[i].clear();
		chainHead[i]=-1;
		chainSize[i]=0;
	}
	ln=log2(n);
	chainNo=0;
	ptr=0;
}

void solve()
{
	int i,a,b;
	cin>>n;
	preprocess();
	
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	dfs(0,0);
	HLD(0,0);
	
	level=askd(0);
	if(level==0)
	{
		print(0);
		return;
	}
	query(0);
}

int32_t main()
{
	//ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}