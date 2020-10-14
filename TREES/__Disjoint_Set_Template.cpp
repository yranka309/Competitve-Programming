#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100001
int par[N],ans=0,sz[N];
vector<pr> g[N];

int parent(int x)
{
	if(par[x]==x)	return x;
	return par[x]=parent(par[x]);
}

void merge(int a,int b)
{
	int x=parent(a);
	int y=parent(b);
	if(x==y)	return;
	ans+=sz[x]*sz[y];
	par[y]=x;
	sz[x]+=sz[y];
}
 
void solve()
{
	int n,q,x,y,w,i;
	cin>>n>>q;
	int aans[n+1];
	for(i=1;i<=n;i++)
		par[i]=i,sz[i]=1;
	for(i=1;i<n;i++)
	{
		cin>>x>>y>>w;
		int k=1;
		while(k*k<=w)
		{
			if(w%k==0)
			{
				g[k].pb({x,y});
				if(k*k!=w)
					g[w/k].pb({x,y});
			}
			k++;
		}
	}
	for(i=1;i<N;i++)
	{
		ans=0;
		for(auto p:g[i])
			merge(p.fi,p.se);
		aans[i]=ans;
		for(auto p:g[i])
			sz[p.fi]=sz[p.se]=1;
	}
	while(q--)
	{
		cin>>x;
		cout<<aans[x]<<endl;
	}
	
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}