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
#define N 200005
int n;
vector<int> a(N),seg(4*N),lazy(4*N);

int assign(int a,int b)
{
	return  min(a,b);
}

void build(int pos=0,int l=0,int r=n-1)
{
	if(l==r)
	{
		seg[pos]=1e9;
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=(r-l+1)*x;
}

// PART OF LAZY PROPAGATION
void shift(int pos,int l,int r)
{
	int mid=(l+r)/2;
	upd(2*pos+1,l,mid,lazy[pos]);
	upd(2*pos+2,mid+1,r,lazy[pos]);
	lazy[pos]=0;
}

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		//upd(pos,l,r,v);
		seg[pos]=min(seg[pos],v);
		return;
	}
	shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=assign(seg[2*pos+1],seg[2*pos+2]);
}

int query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return 1e9;
	if(x<=l && y>=r)
		return seg[pos];
	shift(pos,l,r);
	int mid=(l+r)/2;
	return assign(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

set<char> vowel={'a','e','i','o','u','A','E','I','O','U'};

void solve()
{
	string s;
	cin>>s;
	n=s.length();
	int a[n],i;
	for(i=0;i<n;i++)
	{
		if(vowel.count(s[i]))
			a[i]=-1;
		else
			a[i]=2;
		if(i)
			a[i]+=a[i-1];
	}
	build();
	
	int ans1=0,ans2=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			ans1=i+1;
			ans2=1;
		}
		else
		{
			int x=-a[i];
			int val=query(x,n-1);
			int l=i-val;
			if(l>ans1)
			{
				ans1=l;
				ans2=1;
			}
			else if(l==ans1)
				ans2++;
			update(x,x,i);
		}
	}
	
	if(ans1)
		cout<<ans1<<" "<<ans2<<endl;
	else
		cout<<"No solution"<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}