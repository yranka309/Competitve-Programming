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

void suffix_Array(string s,vector<int> &p)
{
	int n=s.length(),i;
	vector<pair<char,int > > a(n);
	vector<int> c(n);
	p.resize(n);
	
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

int check(string &s,string &s1,int idx)
{
	int n=s1.size(),m=s.length(),i=0,j=idx;
	
	while(i<n)
	{
		if(j==m)
			return -1;
		if(s1[i]<s[j])
			return 1;
		if(s1[i]>s[j])
			return -1;
		i++;
		j++;
	}
	return 0;
}

int upper_search(string &s,string &s1,vector<int> &p)
{
	int low=1,high=p.size()-1,mid,val,ans=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		val=check(s,s1,p[mid]);
		if(val==0)
		{
			ans=mid;
			low=mid+1;
		}
		if(val==1)
			high=mid-1;
		else if(val==-1)
			low=mid+1;
	}
	return ans;
}

int lower_search(string &s,string &s1,vector<int> &p)
{
	int low=1,high=p.size()-1,mid,val,ans=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		val=check(s,s1,p[mid]);
		if(val==0)
		{
			ans=mid;
			high=mid-1;
		}
		if(val==1)
			high=mid-1;
		else if(val==-1)
			low=mid+1;
	}
	return ans;
}

void solve()
{
	string s;
	cin>>s;
	s+='$';
	int i,n=s.length();
	vector<int> p;
	suffix_Array(s,p);
	
	int q;
	cin>>q;
	while(q--)
	{
		string s1;
		cin>>s1;
		int val1=lower_search(s,s1,p);
		int val2=upper_search(s,s1,p);
		if(val1==-1)
			cout<<0<<endl;
		else
			cout<<val2-val1+1<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}