#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int add(int a,int b,int m=mod){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;


vector<vector<int> > multiply(vector<vector<int> > a,vector<vector<int> > b)
{
	int n=a.size();
	vector<vector<int> > c(n,vector<int> (n,0));
	int i,j,k;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				//c[i][j]+=a[i][k]*b[k][j];
				c[i][j]=add(c[i][j],mul(a[i][k],b[k][j]));
			}
		}
	}
	return c;
}

vector<vector<int> > power(vector<vector<int> > a,int b)
{
	int n=a.size(),i,j;
	vector<vector<int> > res(n,vector<int> (n,0));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			res[i][j]=(i==j);
	
	while(b)
	{
		if(b%2)
			res=multiply(res,a);
		a=multiply(a,a);
		b/=2;
	}
	return res;
}

void solve()
{
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}