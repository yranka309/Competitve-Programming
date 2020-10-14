#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 200005
vector<int> g[N];
int color[N],st[N],ft[N];//start and finish time of every vertex

//start time finish time
int Time=0;
void dfs(int v)
{
	st[v]=Time++;
	color[v]=1;
	for(auto u:g[v])
	{
		if(color[u]==0)
		{
			dfs(u);
		}
	}
	color[v]=2;
	ft[v]=Time++;
}

void solve()
{
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}