#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define mod1 1000000007
#define mod2 1000000009
#define mod3 1000000021
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
#define N 600005
int p1[N],p2[N],p3[N];

unordered_map<int,int> hash1,hash2,hash3;

void fun()
{
	p1[0]=11;
	p2[0]=7;
	p3[0]=5;
	for(int i=1;i<N;i++)
	{
		p1[i]=mul(p1[i-1],11,mod1);
		p2[i]=mul(p2[i-1],7,mod2);
		p3[i]=mul(p3[i-1],5,mod3);
	}
}

void insert(string s)
{
	int val1=0,val2=0,val3=0,n=s.length(),i;
	for(i=0;i<n;i++)
	{
		val1=add(val1,mul(s[i]-'a'+1,p1[i],mod1),mod1);
		val2=add(val2,mul(s[i]-'a'+1,p2[i],mod2),mod2);
		val3=add(val3,mul(s[i]-'a'+1,p3[i],mod3),mod3);
	}
	hash1[val1]=1;
	hash2[val2]=1;
	hash3[val3]=1;
}

bool search(string s)
{
	int val1=0,val2=0,val3=0,n=s.length(),i,j;
	for(i=0;i<n;i++)
	{
		val1=add(val1,mul(s[i]-'a'+1,p1[i],mod1),mod1);
		val2=add(val2,mul(s[i]-'a'+1,p2[i],mod2),mod2);
		val3=add(val3,mul(s[i]-'a'+1,p3[i],mod3),mod3);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			int x=j-s[i]+'a';
			int y1=(x+mod1)%mod1;
			int y2=(x+mod2)%mod2;
			int y3=(x+mod3)%mod3;
			if(y1==0)
				continue;
			
			y1=mul(y1,p1[i],mod1);
			y2=mul(y2,p2[i],mod2);
			y3=mul(y3,p3[i],mod3);
			
			int v1=add(val1,y1,mod1);
			int v2=add(val2,y2,mod2);
			int v3=add(val3,y3,mod3);
			
			if(hash1.find(v1)!=hash1.end() && hash2.find(v2)!=hash2.end() && hash3.find(v3)!=hash3.end())
				return true;
		}
	}
	return false;
}

void solve()
{
	fun();
	int n,m,i;
	cin>>n>>m;
	string s;
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert(s);
	}
	for(i=0;i<m;i++)
	{
		cin>>s;
		if(search(s))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}