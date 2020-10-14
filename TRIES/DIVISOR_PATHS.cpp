#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 998244353
#define endl "\n"
int fact[105],invfact[105];

int power(int a,int b)
{
	if(b==1)	return a;
	int res=power(a,b/2);
	res=(res*res)%mod;
	if(b%2)	res=(res*a)%mod;
	return res;
}

int modinv(int a)
{
	return power(a,mod-2);
}

vector<int> divisor(int d)
{
	vector<int> ans;
	for(int i=2;i*i<=d;i++)
	{
		if(d%i==0)
			ans.pb(i);
		while(d%i==0)
			d/=i;
	}
	if(d>1)
		ans.pb(d);
	return ans;
}

void fun()
{
	int i;
	fact[0]=1;
	for(i=1;i<105;i++)
		fact[i]=(i*fact[i-1])%mod;
	invfact[104]=modinv(fact[104]);
	for(i=103;i>=0;i--)
		invfact[i]=((i+1)*invfact[i+1])%mod;
}
 
void solve()
{
	int d,q,a,b,ans=1;
	cin>>d>>q;
	vector<int>prime=divisor(d);
	while(q--)
	{
		vector<int> val1,val2;
		cin>>a>>b;
		ans=1;
		for(auto x:prime)
		{
			int cnt=0;
			while(a%x==0)
			{
				cnt++;
				a/=x;
			}
			while(b%x==0)
			{
				cnt--;
				b/=x;
			}
			if(cnt>0)	val1.pb(abs(cnt));
			if(cnt<0)	val2.pb(abs(cnt));
		}
		int sum1=0,sum2=0;
		for(auto x:val1)
		{
			ans=(ans*invfact[x])%mod;
			sum1+=x;
		}
		for(auto x:val2)
		{
			ans=(ans*invfact[x])%mod;
			sum2+=x;
		}
		ans=((ans*fact[sum1])%mod*fact[sum2])%mod;
		cout<<ans<<endl;
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	fun();
	while(t--)
	{
		solve();
	}
	return 0;
}