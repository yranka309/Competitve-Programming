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
ll fac[21];
map<ll,ll> mp,mp1;

ll ncr(ll n,ll r)
{
	return fac[n]/(fac[n-r]*fac[r]);
}

void solve()
{
	ll n,i,ans=0,mask;
	cin>>n;
	ll arr[n];
	fac[0]=0;
	for(i=1;i<21;i++)
		fac[i]=fac[i-1]*i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(mask=1;mask<(1<<n);mask++)
	{
		//cout<<"mAAA SK iss  "<<mask<<endl;
		ll sum=0;
		mp.clear();
		for(i=0;i<n;i++)
		{
			if(mask&(1<<i))
				sum+=arr[i];
		}
		if(sum%2)	continue;
		for(i=0;i<n;i++)
		{
			if(mask&(1<<i))
			{
				for(auto x:mp)
					mp1[x.fi+arr[i]]=1;
				mp1[arr[i]]=1;
			}
			for(auto x:mp1)
				mp[x.fi]=1;
			mp1.clear();
		}
		/*cout<<"mask is  "<<mask<<"  "<<sum<<endl;
		for(auto xx:mp)
			cout<<xx.fi<<"  ";
		cout<<endl;*/
		if(mp[sum/2])
			ans++;
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
