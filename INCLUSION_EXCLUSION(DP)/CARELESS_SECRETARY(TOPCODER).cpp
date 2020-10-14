#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define maxm 1e18
#define minm -1e18
#define pr pair<ll,ll>
#define mod 1000000007
ll fac[1001];

void add(ll &x,ll y)
{
	x=(x+y)%mod;
}
 
void solve()
{
	ll n,k,ans=0,mask,i;
	cin>>n>>k;
	fac[0]=1;
	for(i=1;i<1001;i++)
		fac[i]=(i*(fac[i-1])%mod)%mod;
	for(mask=0;mask<(1<<k);mask++)
	{
		ll x=__builtin_popcount(mask);
		if(x%2==0)
			add(ans,fac[n-x]);
		else
			add(ans,mod-fac[n-x]);
	}
	cout<<ans<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
