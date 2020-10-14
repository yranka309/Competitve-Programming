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
vector<int> g[N];
int root,visit[N],disc[N],low[N],Time=0,art[N];
//disc=discovery time of node u
//low =low time of node v
//root = root node of tree
void dfs(int u,int parent)
{
	low[u]=disc[u]=Time++;
	visit[u]=1;
	int child=0;
	for(auto v:g[u])
	{
		if(v==parent)	continue;
		if(!visit[v])
		{
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(u==root && child>1)		art[root]=1;
			if(u!=root && low[v]>=disc[u])art[u]=1;
		}
		low[u]=min(low[u],disc[v]);
	}
}

void solve()
{
	int n,m,i,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	root=4;
	memset(visit,0,sizeof(visit));
	memset(art,0,sizeof(art));
	dfs(root,root);
	for(i=1;i<=n;i++)
		if(art[i])
			cout<<i<<" ";
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}

/*
8 9	//n,m
1 2
2 3
1 3
3 4
4 5
5 6
6 7
5 7
6 8

root = 4;
articulation point = 3,4,5,6
*/