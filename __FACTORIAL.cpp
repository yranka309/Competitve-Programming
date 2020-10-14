#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 1001
int fac[N],ifac[N];


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

void fun()
{
	int i;
	fac[0]=1;
	for(i=1;i<N;i++)
		fac[i]=(fac[i-1]*i)%mod;
	ifac[N-1]=modinv(fac[N-1]);
	for(i=N-2;i>=0;i--)
		ifac[i]=(ifac[i+1]*(i+1))%mod;
}

void add(int &a,int b)
{
	a=(a+b)%mod;
}

void solve()
{
	int n,k,i,ans=0;
	cin>>n>>k;
	for(i=0;i<=k;i++)
	{
		//cout<<fac[n]<<" "<<ifac[i]<<"  "<<ifac[n-i]<<endl;
		int val=((ifac[i]*ifac[n-i])%mod*fac[n])%mod;
		add(ans,val);
		//cout<<ans<<" "<<val<<endl;
	}
	cout<<ans<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;
	fun();
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}