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
int n;
int seg[4*N][2][2];
string a;

int add(int a,int b,int m=mod){	int c=(a+b);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a-b);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;

void multiply(int pos,int pos1,int pos2)
{
	int n=2,i,j,k;
	for(i=0;i<2;i++)for(j=0;j<2;j++)	seg[pos][i][j]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				seg[pos][i][j]=add(seg[pos][i][j],mul(seg[pos1][i][k],seg[pos2][k][j]));
}

void assign(int pos,char c)
{
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)	seg[pos][i][j]=0;
	if(c=='?')
	{
		seg[pos][0][0]=19;
		seg[pos][0][1]=7;
		seg[pos][1][0]=6;
		seg[pos][1][1]=20;
	}
	else if(c=='H')
		seg[pos][1][0]=seg[pos][0][0]=1;
	else if(c=='S' || c=='D')
		seg[pos][0][1]=seg[pos][1][1]=1;
	else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		seg[pos][0][1]=seg[pos][1][0]=1;
	else
		seg[pos][0][0]=seg[pos][1][1]=1;
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		assign(pos,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	multiply(pos,2*pos+1,2*pos+2);
}

void update(int x,int y,char v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		assign(pos,v);
		return;
	}
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	multiply(pos,2*pos+1,2*pos+2);
}

void solve()
{
	int q,x;
	cin>>n>>q>>a;
	memset(seg,0,sizeof(seg));
	build();
	char c;
	cout<<seg[0][0][0]<<endl;
	while(q--)
	{
		cin>>x>>c;
		x--;
		update(x,x,c);
		cout<<seg[0][0][0]<<endl;
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}