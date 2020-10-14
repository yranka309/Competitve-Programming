#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N 5005
#define NN 25000005

int good[N][N],M=1;
int val[NN],ch[NN][2],sum[NN];

int alc(int &x)
{
	if(!x)
		x=++M;
	return x;
}

void solve()
{
	string s;
	cin>>s;
	int k,i,j,l,n=s.length(),cur;
	cin>>k;
	memset(val,0,sizeof(val));
	memset(ch,0,sizeof(ch));
	memset(sum,0,sizeof(sum));
	for(l=0;l<n;l++)
	{
		for(i=0;i+l<n;i++)
		{
			j=i+l;
			if(s[i]!=s[j])	continue;
			if(i+2<=j-2 && !good[i+2][j-2])	continue;
			good[i][j]=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		cur=1;
		for(j=i;j<n;j++)
		{
			cur=alc(ch[cur][s[j]-'a']);
			val[cur]+=good[i][j];
		}
	}
	for(int i=M;i>0;i--) 
		sum[i]=sum[ch[i][0]]+sum[ch[i][1]]+val[i];
		
	string res;
	cur=1;
	
	while(k>val[cur])
	{
		k-=val[cur];
		if(sum[ch[cur][0]]>=k) cur=ch[cur][0], res+="a";
		else k-=sum[ch[cur][0]], cur=ch[cur][1], res+="b";
	}
	cout<<res<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}