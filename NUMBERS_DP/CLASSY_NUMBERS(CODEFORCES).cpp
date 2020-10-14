#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int calc(int val)
{
	string s=to_string(val);
	int n=s.length(),i,j,k,l,ans=0;
	vector<vector<int > > dp(5,vector<int>(2));
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		vector<vector<int > > new_dp(5,vector<int>(2));
		for(j=0;j<2;j++)
		{
			for(l=0;l<4;l++)
			{
				for(k=0;k<10;k++)
				{
					if(j==0 && k>(s[i]-'0'))	continue;
					else if(j==0 && k==(s[i]-'0'))	new_dp[l+1-(k==0)][j]+=dp[l][j];
					else
						new_dp[l+1-(k==0)][1]+=dp[l][j];
				}
			}
		}
		dp=new_dp;
	}
	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
			ans+=dp[j][i];
	return ans;
}
 
void solve()
{
	int l,r;
	cin>>l>>r;
	cout<<calc(r)-calc(l-1)<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}