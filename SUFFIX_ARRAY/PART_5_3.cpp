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
#define N 500005
vector<int> lcp,p,c;
string s;
int dp[22][N];

struct node{
	int l,r,len;
};

void count_sort(vector<int> &p,vector<int> &c)
{
	int n=p.size();
	vector<int> cnt(n);
	for(auto x:c)
		cnt[x]++;
	vector<int> p_new(n),pos(n);
	
	pos[0]=0;
	for(int i=1;i<n;i++)
		pos[i]=pos[i-1]+cnt[i-1];
	
	for(auto x:p)
	{
		p_new[pos[c[x]]]=x;
		pos[c[x]]++;
	}
	p=p_new;
}

void LCP()
{
	int n=p.size(),k=0,i;
	for(i=0;i<n-1;i++)
	{
		int x=c[i];
		int j=p[x-1];
		//lcp[i]= lcp[s[i..],s[j...]]
		while(s[i+k]==s[j+k])
			k++;
		lcp[x]=k;
		k=max(k-1,0ll);
	}
}

void suffix_Array()
{
	int n=s.length(),i;
	vector<pair<char,int > > a(n);
	
	for(i=0;i<n;i++)
		a[i]={s[i],i};
	sort(a.begin(),a.end());
	
	for(i=0;i<n;i++)
		p[i]=a[i].se;
	c[p[0]]=0;
	for(i=1;i<n;i++)
	{
		if(a[i].fi==a[i-1].fi)
			c[p[i]]=c[p[i-1]];
		else
			c[p[i]]=c[p[i-1]]+1;
	}
	
	int k=0;
	vector<int> c_new(n);
	while((1<<k)<n)
	{
		for(i=0;i<n;i++)
			p[i]=(p[i]-(1<<k)+n)%n;
		
		count_sort(p,c);
		
		c_new[p[0]]=0;
		for(i=1;i<n;i++)
		{
			pr prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
			pr now={c[p[i]],c[(p[i]+(1<<k))%n]};
			if(prev==now)
				c_new[p[i]]=c_new[p[i-1]];
			else
				c_new[p[i]]=c_new[p[i-1]]+1;
		}
		c=c_new;
		k++;
	}
}

void sparseTable()
{
	int i,j,n=p.size();
	int ln=log2(n);
	for(i=0;i<n;i++)
		dp[0][i]=lcp[i];
	
	for(i=1;i<=ln;i++)
		for(j=0;j<n;j++)
		{
			int k=j+(1<<i);
			if(k>n)
				break;
			k=j+(1<<(i-1));
			dp[i][j]=min(dp[i-1][j],dp[i-1][k]);
		}
}

int query(int i,int j)
{
	if(i==j)
		return lcp[i];
	int val=0;
	while((i+(1<<val))<=j)
		val++;
	val--;
	// cout<<"val is "<<val<<endl;
	// cout<<i<<" "<<j+1-(1<<(val))<<endl;
	return min(dp[val][i],dp[val][j+1-(1<<(val))]);
}

bool comp1(node a,node b)
{
	if(a.l==b.l)
		return a.r<b.r;
	int len=min(a.len,b.len);
	int st=c[a.l];
	int en=c[b.l];
	int x=query(min(st,en)+1,max(st,en));
	if(x>=len)
	{
		if(a.len==b.len)
			return a.l<b.l;
		else
			return a.len<b.len;
	}
	return st<en;
}

void solve()
{
	cin>>s;
	char ch=30;
	s+=ch;
	int i,n=s.length();
	
	memset(dp,0,sizeof(dp));
	c.resize(n);
	p.resize(n);
	lcp.resize(n,0);
	
	suffix_Array();
	LCP();
	sparseTable();
	
	int m,x,y;
	cin>>m;
	node a[m];
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--,y--;
		a[i]={x,y,y-x+1};
	}
	sort(a,a+m,comp1);
	
	for(i=0;i<m;i++)
		cout<<a[i].l+1<<" "<<a[i].r+1<<endl;
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}