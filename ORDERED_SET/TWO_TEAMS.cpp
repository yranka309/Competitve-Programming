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

void solve()
{
	int n,k;
	cin>>n>>k;
	int a[n],ans[n],i,x=1;
	memset(ans,0,sizeof(ans));
	ordered_set os;
	set<int> s;
	map<int,int> mp;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
		os.insert(i);
		mp[a[i]]=i+1;
		s.insert(i);
	}
	for(i=n-1;i>=0;i--)
	{
		if(s.count(i))
		{
			int idx=mp[i]-1;
			int val=os.order_of_key(idx);
			int size=s.size();
			//cout<<"i and val are  "<<i<<" "<<val<<" "<<endl;
			for(int j=min(val+k,size-1);j>=max((int)0,val-k);j--)
			{
				int y=*(os.find_by_order(j));
				os.erase(y);
				s.erase(a[y]);
				//cout<<"y is  "<<y<<" "<<a[y]<<endl;
				ans[y]=x;
			}
			x=3-x;
		}
	}
	for(i=0;i<n;i++)
		cout<<ans[i];
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