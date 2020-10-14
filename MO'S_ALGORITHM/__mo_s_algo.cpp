#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 200005

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





inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct query{
	int l,r,idx;
	int64_t ord;
 
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 22, 0);
	}
};

inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}




int block,a[N];		//bolck=N/sqrt(N);
long long cur=0,freq[1000005];
query qr[N];
vector<int> ans;





void add(int x)
{
	cur-=freq[x]*freq[x]*x;
	freq[x]++;
	cur+=freq[x]*freq[x]*x;
}

void remove(int x)
{
	cur-=freq[x]*freq[x]*x;
	freq[x]--;
	cur+=freq[x]*freq[x]*x;
}

void evaluate(int q)
{
	int cl=1,cr=0,i;
	for(i=1;i<=q;i++)
	{
		int r=qr[i].r;
		int l=qr[i].l;
		while(cr<r)	add(a[++cr]);
		while(cl>l)	add(a[--cl]);
		while(cl<l)	remove(a[cl++]);
		while(cr>r)	remove(a[cr--]);
		ans[qr[i].idx]=cur;
	}
}

void solve()
{
	int n,i,x,y,q;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	memset(freq,0,sizeof(freq));
	ans.resize(q+1);
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		qr[i].l=x;
		qr[i].r=y;
		qr[i].idx=i;
		qr[i].calcOrder();
	}
	block=n/sqrt(n);
	sort(qr+1,qr+q+1);
	evaluate(q);
	for(i=1;i<=q;i++)
		cout<<ans[i]<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}