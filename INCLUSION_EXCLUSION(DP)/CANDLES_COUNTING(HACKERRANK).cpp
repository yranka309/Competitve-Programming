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
#define MAX_N 50001
ll dp[MAX_N],ft[MAX_N];

void add(ll &x,ll y)
{
	x=(x+y)%mod;
}

void update(ll i,ll x)
{
	for(;i<MAX_N;i+=i&(-i))
		add(ft[i],x);
}

ll query(ll i)
{
	ll sum=0;
	for(;i>0;i-=i&(-i))
		add(sum,ft[i]);
	return sum;
}
 
void solve()
{
	ll n,k,i,ans=0,mask;
	cin>>n>>k;
	ll h[n],c[n];
	for(i=0;i<n;i++)
		cin>>h[i]>>c[i];
	ll res=0;
	for(mask=0;mask<(1<<k);mask++)
	{
		//cout<<"mask  "<<mask<<"  "<<k<<endl;
		memset(ft,0,sizeof(ft));
		ll tmp=0;
		for(i=0;i<n;i++)
		{
			if(mask&(1<<(c[i]-1)))
			{
				dp[i]=1+query(h[i]-1);
				update(h[i],dp[i]);
				add(tmp,dp[i]);
			}
		}
		if(__builtin_popcount(mask)%2==k%2)
			add(res,tmp);
		else
			add(res,mod-tmp);
	}
	cout<<res<<endl;
	return;
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
