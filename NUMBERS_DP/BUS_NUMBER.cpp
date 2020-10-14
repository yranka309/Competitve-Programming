#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int fact[21],cnt[10];

void fun()
{
	fact[0]=1;
	for(int i=1;i<21;i++)	fact[i]=(fact[i-1]*i);
}

int cal(int first_digit,int p,int cur_digit,int l)
{
	int i,ans=0;
	if(cur_digit==10)
		return fact[l]/p;
	if(cnt[cur_digit]==0 || cur_digit==first_digit)
		ans+=cal(first_digit,p,cur_digit+1,l);
	for(i=1;i<=cnt[cur_digit];i++)
		ans+=cal(first_digit,p*fact[i],cur_digit+1,l+i);
	return ans;
}
 
void solve()
{
	fun();
	int n,i,ans=0;
	cin>>n;
	memset(cnt,0,sizeof(cnt));
	int m=n;
	while(m)
	{
		cnt[m%10]++;
		m/=10;
	}
	for(i=1;i<10;i++)
	{
		if(cnt[i]>0)
		{
			cnt[i]--;
			ans+=cal(i,1,0,0);
			cnt[i]++;
		}
	}
	cout<<ans<<endl;
	
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}