#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 50005
int ln = 20; 

vector<int> g[N],ans,prime,val(N),dist;
int par[N],dp[22][N],sub[N],lvl[N];
vector<bool> marked;
int n,cnt=0;

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

void dfs3(int u,int p,int d,int mul)
{
	dist[d]+=mul;
	for(auto v:g[u])
	{
		if(v==p || marked[v])
			continue;
		dfs3(v,u,d+1,mul);
	}
}

int dfs4(int u,int p,int d)
{
	int aa=0;
	for(auto x:prime)
	{
		if(x<d)
			continue;
		if(!dist[x-d])
			break;
		aa+=dist[x-d];
		if(x==d)
			aa+=dist[x-d];
	}
	for(auto v:g[u])
	{
		if(v==p || marked[v])
			continue;
		aa+=dfs4(v,u,d+1);
	}
	return aa;
}

void decompose(int u,int p=-1)
{
	dfs1(u,u);
	nn=sub[u];
	int centroid=dfs2(u,u),xx=0;
	
	// write code here
	for(auto &z:dist)
		z=0;
	dfs3(centroid,centroid,0,1);
	
	for(auto v:g[centroid])
	{
		if(marked[v])
			continue;
		dfs3(v,centroid,1,-1);
		xx+=dfs4(v,centroid,1);
		dfs3(v,centroid,1,1);
	}
	cnt+=xx/2;
	marked[centroid]=true;
	for(auto v:g[centroid])
	{
		if(!marked[v])
			decompose(v,centroid);
	}
}

void assign()
{
	marked.resize(n,false);
	ans.resize(n);
	dist.resize(n);
	int i,j;
	for(i=0;i<N;i++)
		val[i]=1;
	for(i=2;i<N;i++)
	{
		if(val[i])
		{
			prime.pb(i);
			for(j=i*i;j<N;j+=i)
				val[j]=0;
		}
	}
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
	//cout<<cnt<<endl;
	decompose(0,-1);
	
	//cout<<"cnt is "<<cnt<<endl;
	double ans=(2.0*cnt)/(n*(n-1));
	cout<<fixed<<setprecision(10)<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}