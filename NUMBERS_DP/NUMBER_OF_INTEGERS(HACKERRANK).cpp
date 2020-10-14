#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;
int K;

int _add(int val)
{
	return (val!=0);
}

int fun(string &s)
{
	int i,j,k,l,n=s.size();
	vector< vector<int> > ndp(K+2,vector<int> (2,0));
	ndp[0][0]=1;
	// j=0 means equal
	// j=1 means lesser
	for(i=0;i<n;i++)
	{
		vector< vector<int> > dp(K+2,vector<int> (2,0));
		for(j=0;j<2;j++)
		{
			for(k=0;k<=K;k++)
			{
				for(l=0;l<10;l++)
				{
					int x=s[i]-'0',ll;
					int y=_add(l);
					//if(k==1 && j==0)
					if(ndp[k][j]==0)	continue;
					if(j==0)
					{
						if(l<x)
							dp[k+y][1]=add(dp[k+y][1],ndp[k][j]);
						else if(l==x)
							dp[k+y][0]=add(dp[k+y][0],ndp[k][j]);
						else
							break;
					}
					else
						dp[k+y][j]=add(dp[k+y][j],ndp[k][j]);
				}
			}
		}
		ndp=dp;
	}
	return add(ndp[K][1],ndp[K][0]);
}

void solve()
{
	
	//In this problem, we have to find no of integers in range (l,r] which have k non-zero integers
	//in its decimal representation
	string l,r;
	cin>>l>>r>>K;
	cout<<sub(fun(r),fun(l))<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}
/*

input 