#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 60005
int t[N],n;
struct node{
	int val,l,r,idx;
};

void update(int p)
{
	for(p+=n;p>0;p>>=1)
		t[p]++;
}

int query(int l,int r)
{
	int res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)	res+=t[l++];
		if(r&1)	res+=t[--r];
	}
	return res;
}

bool comp(node a,node b)
{
	return a.val>b.val;
}
 
void solve()
{
	memset(t,0,sizeof(t));
	cin>>n;
	int i,q;
	pr a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a,a+n);
	cin>>q;
	int ans[q],j=n-1;
	node b[q];
	for(i=0;i<q;i++)
	{
		cin>>b[i].l>>b[i].r>>b[i].val;
		b[i].idx=i;
	}
	sort(b,b+q,comp);
	for(i=0;i<q;i++)
	{
		int val=b[i].val;
		int l=b[i].l;
		int r=b[i].r;
		while(j>=0 && a[j].fi>val)
		{
			update(a[j].se);
			j--;
		}
		ans[b[i].idx]=query(l-1,r);
	}
	for(i=0;i<q;i++)
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