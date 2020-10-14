#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100005

struct query{
	int l,r,idx,k;
};
query q[N];
vector<int> g[N];
int a[N],id[N],val[N],bit[N];
int bsz,n,m,T=1,tin[N],tout[
N];//in and out time of every node

bool comp(query q1,query q2)
{
	int a=q1.l/bsz;
	int b=q2.l/bsz;
	if(a==b)	return q1.r<q2.r;
	return a<b;
}

int getparent(int i)
{
	return i-(i&(-i));
}

int getnext(int i)
{
	return i+(i&(-i));
}

int getsum(int r)		//calculating sum from 1-r
{
	int sum=0;
	while(r>0)
	{
		sum+=bit[r];
		r=getparent(r);
	}
	return sum;
}

void update(int i,int value)
{
	while(i<=N)
	{
		bit[i]+=value;
		i=getnext(i);
	}
}

void remove(int x)
{
	update(N-val[x],-1);
	val[x]--;
	update(N-val[x],1);
}

void add(int x)
{
	update(N-val[x],-1);
	val[x]++;
	update(N-val[x],1);
}

void compute()
{
	int curl=q[0].l,curr=q[0].l-1,res=0,i,ans[m];
	
	for(i=0;i<m;i++)
	{
		while(curl<q[i].l)	remove(id[curl++]);
		while(curl>q[i].l)	add(id[--curl]);
		while(curr<q[i].r)	add(id[++curr]);
		while(curr>q[i].r)	remove(id[curr--]);
		ans[q[i].idx]=getsum(N-q[i].k);
	}
	
	//sort(q,q+m,comp1);
	for(i=0;i<m;i++)
		cout<<ans[i]<<endl;
}

void dfs(int u,int par)
{
	id[T]=a[u];tin[u]=T++;
	for(auto v:g[u])
	{
		if(v==par)	continue;
		dfs(v,u);
	}
	tout[u]=T-1;
}

void solve()
{
	cin>>n>>m;
	bsz=sqrt(n);
	int i,x,y;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(1,1);
	
	for(i=0;i<m;i++)
	{
		cin>>x>>q[i].k;
		q[i].l=tin[x];
		q[i].r=tout[x];
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