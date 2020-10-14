#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define mod1 1000000007
#define mod2 1000000009
#define pr pair<int,int>
#define endl "\n"

int power(int a,int b,int m)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}
int modinv(int a,int m){ return power(a,m-2,m);}
int add(int a,int b,int m){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;

#define N 2000005
#define K 100005
int p1[N],p2[N];
pr ans[N];
map<pr,int> has;
set<int> sets[K];
vector<int> vec[K];

void fun()
{
	p1[0]=29;
	p2[0]=31;
	for(int i=1;i<N;i++)
	{
		p1[i]=mul(p1[i-1],29,mod1);
		p2[i]=mul(p2[i-1],31,mod2);
	}
}

void calc(string s)
{
	int n=s.length(),i,v1=0,v2=0;
	for(i=0;i<n;i++)
	{
		v1=add(v1,mul(p1[i],s[i]-'a'+1,mod1),mod1);
		v2=add(v2,mul(p2[i],s[i]-'a'+1,mod2),mod2);
		ans[i]={v1,v2};
	}
}

pr get(int i,int j)
{
	if(i==0)
		return ans[j];
	pr p=ans[j];
	p.fi=sub(p.fi,ans[i-1].fi,mod1);
	p.fi=mul(p.fi,modinv(p1[i-1],mod1),mod1);
	
	p.se=sub(p.se,ans[i-1].se,mod2);
	p.se=mul(p.se,modinv(p2[i-1],mod2),mod2);

	return p;
}

void solve()
{
	fun();
	int n,k,i;
	cin>>n>>k;
	string s,s1;
	cin>>s;
	int m=s.size();
	for(i=0;i<k;i++)
		s+=s[i];
	int g;
	cin>>g;
	for(i=0;i<g;i++)
	{
		cin>>s1;
		calc(s1);
		pr p=get(0,k-1);
		has[p]=i+1;
	}
	calc(s);
	for(i=0;i<m;i++)
	{
		pr p=get(i,i+k-1);
		//cout<<"i is "<<i<<" "<<i+k-1<<" "<<p.fi<<" "<<p.se<<endl;
		if(has.find(p)!=has.end())
		{
			int x=has[p];
			//cout<<i<<" "<<x<<endl;
			sets[i%k].insert(x);
			vec[i%k].pb(x);
		}
	}
	for(i=0;i<k;i++)
	{
		if(sets[i].size()==n)
		{
			cout<<"YES"<<endl;
			for(auto x:vec[i])
				cout<<x<<" ";
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}