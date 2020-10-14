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
vector<int> g[N];
int a[N],visit[N],parent[N],val=0;

int power(int a,int b)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2);
	res=(res*res)%mod;
	if(b&1)	res=(res*a)%mod;
	return res;
}
int modinv(int a){ return power(a,mod-2);}

void dfs(int st,int par)
{
	//cout<<st<<"  "<<par<<endl;
	if(visit[st]==2)	return ;
	if(visit[st]==1)
	{
		//cout<<"yes"<<endl;
		int cur=par;
		val=1;
		while(cur!=st)
		{
			cur=parent[cur];
			val++;
		}
		return;
	}
	parent[st]=par;
	visit[st]=1;
	for(auto x:g[st])
	{
		dfs(x,st);
	}
	visit[st]=2;
}

void solve()
{
	int n,x,ans=1;
	cin>>n;
	int a[n],i,sum=n;
	memset(visit,0,sizeof(visit));
	memset(parent,0,sizeof(parent));
	for(i=1;i<=n;i++)
	{
		cin>>x;
		g[i].pb(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			val=0;
			dfs(i,i);
			if(val)
				ans=(ans*(power(2,val)-2+mod)%mod)%mod;
			//cout<<"val is "<<val<<"  "<<i<<endl;
			sum-=val;
		}
	}
	ans=(ans*power(2,sum))%mod;
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}