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

ll coprimes_upto_val(vector<ll> primes,ll val)
{
	if(val<2)
		return val;
	ll i,n=primes.size(),mask,sum=0;
	for(mask=1;mask<(1<<n);mask++)
	{
		ll mul=1;
		for(i=0;i<n;i++)
			if(mask&(1<<i))
				mul*=primes[i];
		ll cur=val/mul;
		if(__builtin_popcount(mask)%2)
			sum+=cur;
		else
			sum-=cur;
	}
	return val-sum;
}

void calc_prime(vector<ll> &primes,ll n)
{
	ll i=2;
	while(i*i<=n)
	{
		if(n%i==0)
			primes.pb(i);
		while(n%i==0)
			n/=i;
		i++;
	}
	if(n>1)
		primes.pb(n);
}
 
void solve()
{
	ll n,l,r;
	cin>>n;
	vector<ll> primes;
	calc_prime(primes,n);// calculating all prime factors of n
	/*for(int i=0;i<primes.size();i++)
		cout<<primes[i]<<" ";
	cout<<endl;*/
	cin>>l>>r;
	ll val1=coprimes_upto_val(primes,l-1);
	ll val2=coprimes_upto_val(primes,r);
	cout<<val2-val1<<endl;
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
