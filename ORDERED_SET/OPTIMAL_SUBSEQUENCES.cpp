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

bool comp(pr a,pr b)
{
	if(a.fi==b.fi)
		return a.se<b.se;
	return a.fi>b.fi;
}

void solve()
{
	int n;
	cin>>n;
	int a[n],i,m,x,y;
	pr b[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]={a[i],i};
	}
	sort(b,b+n,comp);
	cin>>m;
	//for(i=0;i<n;i++)
		//cout<<"b is  "<<b[i].fi<<" "<<b[i].se<<endl;
	pair<pr,int> q[m];
	int ans[m];
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		q[i]={{x,y},i};
	}
	sort(q,q+m);
	ordered_set os;
	int j=0;
	for(i=0;i<m;i++)
	{
		pair<pr,int> p=q[i];
		while(j<n && j<p.fi.fi)
		{
			os.insert(b[j].se);
			j++;
		}
		int val=*(os.find_by_order(p.fi.se-1));
		ans[q[i].se]=a[val];
		//cout<<q[i].se<<"  "<<a[val]<<"  "<<os.size()<<" "<<p.fi.fi<<endl;
	}
	
	for(i=0;i<m;i++)
		cout<<ans[i]<<endl;
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