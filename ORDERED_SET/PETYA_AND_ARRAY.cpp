#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair< int,int >, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

void solve()
{
	int n,t,i,sum=0,ans=0;
	cin>>n>>t;
	int a[n];
	ordered_set os;
	for(i=0;i<n;i++)
		cin>>a[i];
	os.insert({0,0});
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		ans+=os.size()-os.order_of_key({sum-t,1e9});
		os.insert({sum,i});
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