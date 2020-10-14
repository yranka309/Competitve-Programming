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
int k;
string s;
int cnt[26],a[26],n;
vector<int> v;

void fun()
{
	int i=0,sum=0;
	while(i<26 && sum+a[i]<k)
		sum+=a[i++];
	k-=sum;
	char c=i+'a';
	cout<<c;
	//cout<<endl<<i<<" "<<a[i]<<endl;
	if(cnt[i]>k)
		return;
	k-=cnt[i];
	
	vector<int> v1;
	
	for(auto x:v)
		if(x+1<n && s[x]==c)
			v1.pb(x+1);
	v=v1;
	
	memset(cnt,0,sizeof(cnt));
	memset(a,0,sizeof(a));
	
	for(auto x:v)
	{
		a[s[x]-'a']+=n-x;
		cnt[s[x]-'a']++;
	}
	if(k>0)
	fun();
}

void solve()
{
	cin>>s>>k;
	memset(cnt,0,sizeof(cnt));
	memset(a,0,sizeof(a));
	int i,sum;
	n=s.length();
	for(i=0;i<n;i++)
	{
		cnt[s[i]-'a']++;
		a[s[i]-'a']+=n-i;
		v.pb(i);
	}
	if(k>(n*(n+1))/2)
	{
		cout<<"No such line."<<endl;
		return;
	}
	fun();
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}