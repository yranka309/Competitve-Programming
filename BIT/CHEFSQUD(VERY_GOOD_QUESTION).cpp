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

int n,a[N],bit[N],max_idx;

void coordinate_compress()
{
	int i;
	set<int> s;
	vector<int> v;
	
	for(i=0;i<n;i++)
		s.insert(a[i]);
	max_idx=s.size()+1;
	for(auto x:s)
		v.pb(x);
	
	for(i=0;i<n;i++)
		a[i]=1+lower_bound(v.begin(),v.end(),a[i])-v.begin();
}

void update(int i,int val)
{
	while(i<=max_idx)
	{
		bit[i]+=val;
		i+=(i&(-i));
	}
}

int getsum(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}

int calc(int val)
{
	for(int i=0;i<=max_idx;i++)	bit[i]=0;
	
	int i=0,j=0,cur_inv=0,ans=0;
	while(i<n)
	{
		update(a[i],1);
		cur_inv+=getsum(max_idx)-getsum(a[i]);
		while(cur_inv>val)
		{
			update(a[j],-1);
			cur_inv-=getsum(a[j]-1);
			j++;
		}
		ans+=(i-j+1);
		i++;
	}
	return ans;
}

int binary_search()
{
	int low=0,high=(n*(n-1))/2,mid;
	int m=(n*(n+1))/2;
	int val=(m+1)/2,ans;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(calc(mid)>=val)
			high=mid-1,ans=mid;
		else
			low=mid+1;
	}
	return ans;
}

void solve()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	coordinate_compress();
	cout<<binary_search()<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;cin>>t;
	while(t--)	solve();
	return 0;
}