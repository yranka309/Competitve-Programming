#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (1ll<<20)
ll freq[N],dp[N][22];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,mask,ans=0;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }
        for(mask=0;mask<N;mask++)
        {
            for(i=0;i<20;i++)
            {
                if(mask&(1<<i))
                {
                    if(i==0)
                        dp[mask][i]=freq[mask]+freq[mask^(1<<i)];
                    else
                        dp[mask][i]=dp[mask][i-1]+dp[mask^(1<<i)][i-1];
                }
                else
                {
                    if(i==0)
                    {
                    	dp[mask][i]=freq[mask];
                    }
                    else
                        dp[mask][i]=dp[mask][i-1];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            ans+=dp[N-1-a[i]][19];
            freq[a[i]]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
