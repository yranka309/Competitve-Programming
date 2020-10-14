#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 100005
int val[N];

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
int add(int a,int b,int m=mod){	return (a+b)%m;}
int sub(int a,int b,int m=mod){	return (a-b+m)%m;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
// x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;

int getparent(int i)
{
	return i-(i&(-i));
}

int getnext(int i)
{
	return i+(i&(-i));
}

int getsum(int r)		//calculating sum from 1-r
{
	int sum=0;
	while(r>0)
	{
		sumsum+val[r];
		r=getparent(r);
	}
	return sum;
}

void update(int i,int value)//updating value at index i
{
	while(i<=N)
	{
		val[i]+=value;
		i=getnext(i);
	}
}

void solve()
{
	memset(val,0,sizeof(val));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}