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
vector<int> g[N],rg[N],v;
int visit[N],Time=0;
pr value[N];
//strongly connected component using kosaraju's algorithm
// g-> graph 	rg-> reverse graph
// value 	store finish time of node and we sort node acc to their finish time

void dfs(int u)
{
	visit[u]=true;
	for(auto v:g[u])
		if(!visit[v])
			dfs(v);
	value[u]={Time++,u};
}

void dfs1(int u)
{
	visit[u]=true;
	v.pb(u);
	for(auto v:rg[u])
		if(!visit[v])
			dfs1(v);
}

bool comp(pr a,pr b)
{
	return a.fi>b.fi;
}

void solve()
{
	int n,m,i,a,b;
	vector<int > ans;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
		rg[b].pb(a);
	}
	memset(visit,0,sizeof(visit));
	for(i=1;i<=n;i++)
		if(!visit[i])
			dfs(i);
	sort(value+1,value+n+1,comp);
	memset(visit,0,sizeof(visit));
	for(i=1;i<=n;i++)
	{
		if(!visit[value[i].se])
		{
			//cout<<"node is "<<value[i].se<<endl;
			v.clear();
			dfs1(value[i].se);
			//for(auto x:v)
			//	cout<<x<<" ";
			//cout<<endl;
			ans=v;
		}
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(auto x:ans)
		cout<<x<<" ";
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}