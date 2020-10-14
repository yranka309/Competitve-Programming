#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 10005

map<int,int> anss;
int chainNo,ptr,n,ln,dp[20][N];
vector<int> g[N],cost[N],indexx[N];
vector<int> chainHead(N),chainInd(N),otherEnd(N);
vector<int> posInBase(N),lvl(N),sub(N);
vector<int> baseArray(N),seg(4*N),lazy(4*N);

/* -------------------------------------Start of Segment Tree-------------------------------------------*/

int assign(int x,int y)
{
	return x+y;
}

void build_tree(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=baseArray[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*pos+1,l,mid);
	build_tree(2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}
/*
// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=(r-l+1)*x;
}

// PART OF LAZY PROPAGATION
void shift(int pos,int l,int r)
{
	int mid=(l+r)/2;
	upd(2*pos+1,l,mid,lazy[pos]);
	upd(2*pos+2,mid+1,r,lazy[pos]);
	lazy[pos]=0;
}*/

void update_tree(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		//upd(pos,l,r,v);
		seg[pos]=v;
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update_tree(x,y,v,2*pos+1,l,mid);
	update_tree(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

int query_tree(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 0;
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return assign(query_tree(x,y,2*pos+1,l,mid),query_tree(x,y,2*pos+2,mid+1,r));
}

/* ----------------------------------------End of Segment Tree-------------------------------------------*/

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
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==p)
			continue;
		otherEnd[indexx[u][i]]=v;
		dfs(v,u,l+1);
		sub[u]+=sub[v];
	}
}

/* --------------------------------------Heavy Light Secompostion Part ----------------------------------*/

void HLD(int u,int c,int p)
{
	if(chainHead[chainNo]==-1)
		chainHead[chainNo]=u;// chainHead -> starting node of chain
	chainInd[u]=chainNo;//chainInd -> chain no of node u
	//Position of this node in baseArray which we will use in segTree
	posInBase[u]=ptr;
	anss[ptr]=u;
	baseArray[ptr++]=c;
	int sc=-1,ncost=-1,i;
	for(i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==p)
			continue;
		if(sc==-1 || sub[v]>sub[sc])
		{
			sc=v;
			ncost=cost[u][i];
		}
	}
	
	if(sc==-1)
		return;
	HLD(sc,ncost,u);
	
	for(i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==p || v==sc)
			continue;
		chainNo++;
		HLD(g[u][i],cost[u][i],u);
	}
}

/*--------------------------------------Dealing with Queries---------------------------------------------*/

int query_up(int u,int v)
{
	if(u==v)	return 0;
	int uchain,vchain=chainInd[v],ans=0;
	//cout<<"u ad v are "<<u<<" "<<v<<endl;
	while(1)
	{
		uchain=chainInd[u];
		if(uchain==vchain)
		{
			if(u==v)
				break;
			ans=assign(ans,query_tree(posInBase[v]+1,posInBase[u]));
			break;
		}
		int val=query_tree(posInBase[chainHead[uchain]],posInBase[u]);
		ans=assign(ans,val);
		u=chainHead[uchain];
		u=dp[0][u];
	}
	return ans;
}

int dist(int u,int v)
{
	int lca=LCA(u,v);
	int val1=query_up(u,lca);//sum of values from u to lca
	int val2=query_up(v,lca);//sum of values from v to lca
	return assign(val1,val2);
}

int nodes(int u,int v)
{
	int uchain,vchain=chainInd[v],ans=0;
	while(1)
	{
		uchain=chainInd[u];
		if(uchain==vchain)
		{
			ans+=-posInBase[v]+posInBase[u]+1;
			return ans;
		}
		ans+=-posInBase[chainHead[uchain]]+posInBase[u]+1;
		u=chainHead[uchain];
		u=dp[0][u];
	}
}

int find(int u,int v,int c)
{
	int uchain,vchain=chainInd[v],ans=0,val,ansindex;
	while(1)
	{
		uchain=chainInd[u];
		val=-posInBase[chainHead[uchain]]+posInBase[u]+1;
		if(val>=c)
		{
			ansindex=posInBase[u]-c+1;
			return anss[ansindex]+1;
		}
		c-=val;
		u=chainHead[uchain];
		u=dp[0][u];
	}
}

int kth(int u,int v,int c)
{
	int lca=LCA(u,v);
	int val1=nodes(u,lca);
	int val2=nodes(v,lca);
	int total=val1+val2-1;
	if(c>total)	return 0;
	if(c<=val1)
		return find(u,lca,c);
	else
		return find(v,lca,val1+val2-c);
	
}

void preprocess()
{
	for(int i=0;i<=n;i++)
	{
		g[i].clear();
		indexx[i].clear();
		cost[i].clear();
		chainHead[i]=-1;
	}
	ln=log2(n);
	chainNo=0;
	ptr=0;
}

void solve()
{
	int i,a,b,c,w;
	cin>>n;
	preprocess();
	for(i=1;i<n;i++)
	{
		cin>>a>>b>>w;
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
		cost[a].pb(w);
		cost[b].pb(w);
		indexx[a].pb(i-1);
		indexx[b].pb(i-1);
	}
	
	dfs(0,0);
	HLD(0,0,0);
	build_tree();
	while(1)
	{
		string s;
		cin>>s;
		if(s[1]=='O')
			return;
		cin>>a>>b;
		a--,b--;
		if(s[0]=='K')
		{
			cin>>c;
			cout<<kth(a,b,c)<<endl;
		}
		else
			cout<<dist(a,b)<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}