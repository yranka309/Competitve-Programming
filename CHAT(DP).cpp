#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
 
void solve()
{
	int n,k;
	cin>>n>>k;
	int i,a[n],dp[n];
	for(i=0;i<n;i++)	cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
			dp[i]=1+min(k,i)+min(n-1-i,k);
		else
		{
			dp[i]=dp[a[i]-1];
			int inc=a[i]-1+k;
			inc=min(inc,n-1);
			if(inc<=i)
				dp[i]+=min(k+1,i-inc);
			dp[i]+=max(min(k,min(i+k,n-1)-max(i,inc)),(int)0);
			//cout<<endl<<"value of i "<<i<<" "<<inc<<" "<<min(k+1,i-inc)<<endl;
		}
		cout<<dp[i]<<" ";
	}
	cout<<endl;
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