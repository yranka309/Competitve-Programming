#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N (1ll<<22)
int main()
{
    ios_base::sync_with_stdio(0);	cin.tie(NULL);
    ll n,i,mask;
    cin>>n;
    ll a[n],val[N],ans[n];
    memset(val,0,sizeof(val));
    for(i=0;i<n;i++){
        cin>>a[i];
        val[a[i]]=a[i];
    }
    for(mask=0;mask<N;mask++)
        for(i=0;i<22;i++)
            if(mask&(1<<i))
                if(!val[mask])
                    val[mask]=val[mask^(1<<i)];
    for(i=0;i<n;i++){
        ans[i]=val[N-1-a[i]];
        if(!ans[i])	ans[i]=-1;
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
