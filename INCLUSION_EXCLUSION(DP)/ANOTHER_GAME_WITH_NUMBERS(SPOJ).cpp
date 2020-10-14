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

ll gcd(ll a,ll b)
{
	if(a==0)	return b;
	return gcd(b%a,a);
}

void lcm(ll &mul,ll val)
{
	mul=(mul*val)/gcd(mul,val);
}
 
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll a[k],i,mask,ans=0;
	for(i=0;i<k;i++)
		cin>>a[i];
	for(mask=1;mask<(1<<k);mask++)
	{
		ll mul=1;
		for(i=0;i<k;i++)
		{
			if(mask&(1<<i))
				lcm(mul,a[i]);
			if(mul>n)	continue;
		}
		ll cur=n/mul;
		if(__builtin_popcount(mask)%2)
			ans+=cur;
		else
			ans-=cur;
	}
	cout<<n-ans<<endl;
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
