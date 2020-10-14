#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int n,m;
int cache[5001][5001];

int dp(int a[],int idx,int k)
{
	if(k==0 || idx+k*m >n  || idx==n)
		return 0;
	int &ans=cache[idx][k];
	if(ans!=-1)	return ans;
	ans=0;
	int val=0;
	for(int j=0;j<m;j++)
		val+=a[idx+j];	//this can also be done by calculating prefix sum
	ans=max(ans,val+dp(a,idx+m,k-1));
	ans=max(ans,dp(a,idx+1,k));
	return ans;
}
 
void solve()
{
	int k;
	cin>>n>>m>>k;
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	memset(cache,-1,sizeof(cache));
	cout<<dp(a,(int)0,k)<<endl;
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