#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

ordered_set remain1,remain2[256];

void solve()
{
	int n,m,i,l,r,l1,r1;
	cin>>n>>m;
	string s;
	cin>>s;
	char c;
	for(i=0;i<n;i++)
	{
		remain1.insert(i);
		remain2[s[i]].insert(i);
	}
	for(i=0;i<m;i++)
	{
		cin>>l>>r>>c;
		l1=*remain1.find_by_order(l-1);
		r1=*remain1.find_by_order(r-1);
		//cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
		auto it=remain2[c].lower_bound(l1);
		while(it!=remain2[c].end() && *it<=r1)
		{
			//cout<<*it<<endl;
			remain1.erase(*it);
			it=remain2[c].erase(it);
		}
	}
	for(auto x:remain1)
		cout<<s[x];
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