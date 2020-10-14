#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 200005
struct query{
	int l,r,idx;
	long long ans;
};
int block,a[N];		//bolck=N/sqrt(N);
long long cur=0,freq[1000005];
query qr[N];

bool comp(query a,query b)
{
	if(a.l/block!=b.l/block)
		return a.l<b.l;
	return a.r<b.r;
}

bool comp1(query a,query b)
{
	return a.idx<b.idx;
}

void add(int x)
{
	cur-=freq[x]*freq[x]*x;
	freq[x]++;
	cur+=freq[x]*freq[x]*x;
}

void remove(int x)
{
	cur-=freq[x]*freq[x]*x;
	freq[x]--;
	cur+=freq[x]*freq[x]*x;
}

void evaluate(int q)
{
	int cl=1,cr=0,i;
	for(i=1;i<=q;i++)
	{
		int r=qr[i].r;
		int l=qr[i].l;
		while(cr<r)	add(a[++cr]);
		while(cl>l)	add(a[--cl]);
		while(cl<l)	remove(a[cl++]);
		while(cr>r)	remove(a[cr--]);
		qr[i].ans=cur;
	}
}

void solve()
{
	int n,i,x,y,q;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	memset(freq,0,sizeof(freq));
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		qr[i]={x,y,i,0};
	}
	block=n/sqrt(n);
	sort(qr+1,qr+q+1,comp);
	evaluate(q);
	sort(qr+1,qr+q+1,comp1);
	for(i=1;i<=q;i++)
		cout<<qr[i].ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}