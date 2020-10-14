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

vector<int> lcp,p,c;
string s;

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

void solve()
{
	int n,k,a,i;
	cin>>n>>k;
	char ch;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ch='a'+a-1;
		s+=ch;
	}
	s+='$';
	n++;
	
	p.resize(n);
	c.resize(n);
	lcp.resize(n,0);
	
	suffix_Array();
	LCP();
	
	int idx=0,size=n-1,val=1;
	
	/*for(i=0;i<n;i++)
		cout<<lcp[i]<<" ";
	cout<<endl;*/
	
	stack<int> st;
	
	for(i=0;i<n;i++)
	{
		if(st.empty())
			st.push(i);
		else
		{
			if(lcp[i]>=lcp[st.top()])
				st.push(i);
			else
			{
				
				while(lcp[st.top()]>lcp[i])
				{
					int x=st.top();
					st.pop();
					int y=st.top();
					int val1=(i-y)*lcp[x];
					//cout<<"x and y are "<<x<<" "<<y<<" "<<lcp[x]<<" "<<i<<" "<<val1<<endl;
					if(val1>size*val)
					{
						val=i-y;
						idx=p[x];
						size=lcp[x];
					}
				}
				st.push(i);
				/*st.pop();
				int y=st.top();
				int val1=(y-x)*lcp[x];
				
				cout<<"x and y are "<<x<<" "<<y<<" "<<lcp[x]<<" "<<i<<endl;
				
				if(val1>size*val)
				{
					val=y-x;
					idx=p[x];
					size=lcp[x];
				}*/
			}
		}
	}
	while(!st.empty())
	{
		int x=st.top();
		st.pop();
		if(st.empty() || lcp[x]==0)
			break;
		int y=st.top();
		int val1=(n-y)*lcp[x];
		//cout<<"x and y are "<<x<<" "<<y<<" "<<lcp[x]<<" "<<i<<" "<<val1<<endl;
		if(val1>size*val)
		{
			val=i-y;
			idx=p[x];
			size=lcp[x];
		}
	}
	
	//cout<<val<<" "<<size<<" "<<idx<<endl;
	cout<<val*size<<endl;
	cout<<size<<endl;
	
	string res=s.substr(idx,size);
	
	for(auto x:res)
	{
		int z=x-'a'+1;
		cout<<z<<" ";
	}
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}