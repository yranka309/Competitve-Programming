#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100000
vector<int> g[N];
int dp[N][2],a[N];

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

void add(int &a,int b){	a=(a+b)%mod;}

void mul(int &a,int b){	b%=mod;a=(a*b)%mod;}

void dfs(int st)
{
	dp[st][0]=1;
	dp[st][1]=0;
	for(auto x:g[st])
	{
		dfs(x);
		mul(dp[st][1],dp[x][0]);
		add(dp[st][1],dp[x][1]*dp[st][0]);
		mul(dp[st][0],dp[x][0]);
	}
	if(a[st]==1)	dp[st][1]=dp[st][0];
	if(a[st]==0)	add(dp[st][0],dp[st][1]);
}

void solve()
{
	int n,i,x;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x;
		g[x].pb(i);
	}
	for(i=0;i<n;i++)
		cin>>a[i];
	dfs(0);
	cout<<dp[0][1]<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}