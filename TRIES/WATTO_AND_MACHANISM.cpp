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
#define N 600005
int T=1,size;
int trie[N][3];
int is_end[N];
string s;

void insert()
{
	int x=0,i,sz=s.size();
	for(i=0;i<sz;i++)
	{
		int cur=s[i]-'a';
		if(trie[x][cur]==-1)
			trie[x][cur]=T++;
		x=trie[x][cur];
	}
	is_end[x]=1;
}

bool check(int idx,int v,int changes)
{
	if(changes>1)
		return false;
	if(idx==size )
		return is_end[v]&(changes==1);
	bool flag=false;
	for(char ch='a';ch<='c';ch++)
	{
		if(trie[v][ch-'a']==-1)	continue;
		flag|= check(idx+1,trie[v][ch-'a'],changes+1-(s[idx]==ch));
	}
	return flag;
}

void solve()
{
	memset(is_end,0,sizeof(is_end));
	memset(trie,-1,sizeof(trie));
	int n,m,i;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert();
	}
	for(i=0;i<m;i++)
	{
		cin>>s;
		size=s.length();
		if(check(0,0,0))
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