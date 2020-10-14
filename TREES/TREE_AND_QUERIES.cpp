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
#define bit 20
int par[N][bit];
int depth[N];
vector<int> g[N];

void dfs(int start,int parent,int d=1)
{
	depth[start]=d;
	par[start][0]=parent;
	for(int i=1;i<bit;i++)
		par[start][i]=par[par[start][i-1]][i-1];
	for(auto x:g[start])
	{
		if(x==parent)	continue;
		dfs(x,start,d+1);
	}
}

int lca(int a,int b)
{
	int i,len=0;
	if(depth[a]>depth[b])
		swap(a,b);
	//cout<<"st  "<<depth[a]<<"  "<<depth[b]<<endl;
	//depth of a is less than depth of b
	for(i=bit-1;i>=0;i--)
	{
		if(depth[par[b][i]]>=depth[a])
		{
			b=par[b][i];
			len+=(1<<i);
		}
	}
	//cout<<"en  "<<depth[a]<<"  "<<depth[b]<<endl;
	if(a==b)
		return len;
	for(i=bit-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
			len+=(1<<(i+1));
		}
	}
	return len+2;
}
 
void solve()
{
	int n,a,b,i,q,x,y,k;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,0);
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>a>>b>>k;
		int ans=1e18;
		//cout<<"yes  "<<a<<" "<<b<<"  "<<x<<"  "<<y<<endl;
		int val1=lca(a,b);
		int val2=min({lca(a,x)+lca(y,b),lca(a,y)+lca(x,b)})+1;
		if(val1%2==k%2)
			ans=min(ans,val1);
		if(val2%2==k%2)
			ans=min(ans,val2);
		//cout<<val1<<"  "<<val2<<"  "<<ans<<" "<<k<<endl;
		if(ans<=k)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
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