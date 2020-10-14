#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 1000005
int lps[N];

int longestPrefixSuffix(string &str)
{
	int n=str.size(),i,len=0;
	lps[0]=0,i=1;
	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
				lps[i++]=len;
		}
	}
	return lps[n-1];
}
 
void solve()
{
	int n,i;
	cin>>n;
	string ans,s,s1,s2;
	cin>>ans;
	for(i=1;i<n;i++)
	{
		cin>>s;
		int len=min(ans.length(),s.length());
		s1=s.substr(0,len);
		s2=ans.substr(ans.length()-len);
		s1+='*'+s2;
		int idx=longestPrefixSuffix(s1);
		for(;idx<s.length();idx++)
			ans+=s[idx];
	}
	cout<<ans<<endl;
}
	
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}