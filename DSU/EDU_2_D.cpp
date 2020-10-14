
// Problem : D. Bosses
// Contest : Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 2
// URL : https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
// Memory Limit : 64 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int add(int a,int b,int m=mod){	int c=(a+b);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a-b);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;

vector<int> par,len;

pr parent(int a)
{
	if(a==par[a])
		return {a,0};
	pr p=parent(par[a]);
	len[a]=(p.se+len[a]);
	par[a]=p.fi;
	return {p.fi,len[a]};
}



void solve()
{
	int n,q,i,a,b,c;
	cin>>n>>q;
	
	par=len=vector<int> (n+1,0);
	for(i=1;i<=n;i++)	par[i]=i;
	while(q--)
	{
		cin>>a>>b;
		if(a==1)
		{
			cin>>c;
			par[b]=c;
			len[b]=1;
		}
		else
		{
			pr p=parent(b);
			cout<<p.se<<endl;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}