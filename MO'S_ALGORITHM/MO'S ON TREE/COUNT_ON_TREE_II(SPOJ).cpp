// x<<1 => x*2		x>>1 => x/2;	cout<<flush;
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 40005
#define M 100005
#define ln 20;

typedef struct Query{
	int l,r,idx,lc,ans;
}query;
query q[M];

vector<int> g[N],vis(N,0),a(N);
int n,m,T=1,dp[ln][N],id[2*N],st[N],en[N];
int lvl[N],block_size,val[N];

bool comp(query a,query b)
{
	int al=(a.l-1)/block_size+1;
	int ar=(a.r-1)/block_size+1;
	int bl=(b.l-1)/block_size+1;
	int br=(b.r-1)/block_size+1;
	
	if(al==bl)
		return ar<br;
	return al<bl;
}

bool comp1(query a,query b)
{
	return a.idx<b.idx;
}

//assigning starting/ending/levels of every node using dfs
void dfs(int u,int par)
{
	id[T]=u,st[u]=T++;
	for(int i=1;i<ln;i++)
		dp[i][u]=dp[i-1][dp[i-1][u]];
	
	for(auto v:g[u])
	{
		if(v==par)	continue;
		lvl[v]=lvl[u]+1;
		dp[0][v]=u;
		dfs(v,u);
	}
	id[T]=u,en[u]=T++;
}

//Finding lowest common ancestor
int lca(int u,int v)
{
	if(lvl[u]>lvl[v])
		swap(u,v);
	int i;
	for(i=ln-1;i>=0;i--)
	{
		if((lvl[v]-(1<<i)) >= lvl[u])
			v=dp[i][v];
	}
	if(u==v)	return u;
	for(i=ln-1;i>=0;i--)
	{
		int x=dp[i][u];
		int y=dp[i][v];
		if(x!=y)
		{
			u=x;
			v=y;
		}
	}
	return dp[0][u];
}

//insert/deletion of elements in mo's algorithm
void check(int x,int &res)
{
	if(vis[x])
	{
		res-=(val[a[x]]==1);
		val[a[x]]--;
	}
	else if(!vis[x])
	{
		val[a[x]]++;
		res+=(val[a[x]]==1);
	}
	
	vis[x]^=1;
}


void compute()
{
	//Performing standard Mo's Algorithm
	int curl=q[0].l,curr=q[0].l-1,res=0,i;
	for(i=0;i<m;i++)
	{
		while(curl<q[i].l)	check(id[curl++],res);
		while(curl>q[i].l)	check(id[--curl],res);
		while(curr<q[i].r)	check(id[++curr],res);
		while(curr>q[i].r)	check(id[curr--],res);
		
		int u=id[curl];
		int v=id[curr];
		
		//Considering Case 2 of mo's algo on trees
		if(q[i].lc!=u && q[i].lc!=v)
			check(q[i].lc,res);
		q[i].ans=res;
		if(q[i].lc!=u && q[i].lc!=v)
			check(q[i].lc,res);
	}
	sort(q,q+m,comp1);
	for(i=0;i<m;i++)
		cout<<q[i].ans<<endl;
}

void solve()
{
	memset(val,0,sizeof(val));
	cin>>n>>m;
	int i,x,y;
	set<int> s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	vector<int> v;
	for(auto x:s)
		v.pb(x);
		
	//	something like path compression
	for(i=1;i<=n;i++)
		a[i]=1+lower_bound(v.begin(),v.end(),a[i])-v.begin();
	
	//Inputting Tree
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	//Preprocess
	lvl[1]=0;
	dp[0][1]=1;
	dfs(1,1);
	
	
	block_size=sqrt(T);
	
	//Inputting queries
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		q[i].lc=lca(x,y);
		if(st[x]>st[y])	swap(x,y);
		if(q[i].lc==x)	q[i].l=st[x],q[i].r=st[y];//Case 1
		else			q[i].l=en[x],q[i].r=st[y];//Case 2
		q[i].idx=i;
	}
	sort(q,q+m,comp);
	compute();
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}