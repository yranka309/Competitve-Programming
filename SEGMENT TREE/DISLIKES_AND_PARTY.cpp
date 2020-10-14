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
	int n;
	cin>>n;
	set<pr> s;
	int ans=(n*(n-1))/2,a[10],i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		{
			cin>>a[j];
			if(j)
				s.insert({min(a[0],a[j]),max(a[0],a[j])});
		}
	ans-=s.size();
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