#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define mx 1e18
 
void solve()
{
	int n;
	cin>>n;
	int cost[n],i;
	string s1,s2;
	for(i=0;i<n;i++)	cin>>cost[i];
	pair<int,string> dp[n][2];
	for(i=0;i<n;i++)
	{
		cin>>s1;
		s2=s1;
		reverse(s2.begin(),s2.end());
		if(i==0)
		{
			dp[0][0]={0,s1};
			dp[0][1]={cost[0],s2};
		}
		else
		{
			dp[i][0].se=s1,dp[i][1].se=s2;
			if(s1>=dp[i-1][0].se)	dp[i][0].fi=dp[i-1][0].fi;
			else				dp[i][0].fi=mx;
			if(s2>=dp[i-1][0].se)	dp[i][1].fi=dp[i-1][0].fi+cost[i];
			else				dp[i][1].fi=mx;
			if(s1>=dp[i-1][1].se)	dp[i][0].fi=min(dp[i-1][1].fi,dp[i][0].fi);
			if(s2>=dp[i-1][1].se)	dp[i][1].fi=min(dp[i-1][1].fi+cost[i],dp[i][1].fi);
		}
	}
	int val=min({dp[n-1][0].fi,dp[n-1][1].fi});
	if(val>=mx)	cout<<"-1"<<endl;
	else		cout<<val<<endl;
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