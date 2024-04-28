#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int M=1e6+5;
int Mn[M],Cnt[M];
ll lcm[M];
void init()
{
    lcm[1]=1;
    for(int i=2;i<M;++i)
        if(!Mn[i])
        {
            lcm[Mn[i]=i]=3;
            Cnt[i]=1;
            for(int j=i+i;j<M;j+=i)
                if(!Mn[j])Mn[j]=i,Cnt[j]=Cnt[j/i]+1;
        }
        else lcm[i]=lcm[i/Mn[i]]/(2*Cnt[i]-1)*(2*Cnt[i]+1);
}
namespace T
{
    int gcd[M],num[M];
    void solve()
    {
        int n,a;
        cin>>a>>n;
        ++num[gcd[1]=1];
        ll ans=0;
        for(int i=2;i<=n;++i)
        {
            int m=gcd[i/Mn[i]];
            // if(i==5)cout<<i<<' '<<Mn[i]<<'\n';
            if(a/m%Mn[i]==0)
                m*=Mn[i];
            ++num[gcd[i]=m];
            // cout<<gcd[i]<<'\n';
        }
        for(int i=1;i<=n;++i)
            ans+=num[i]*lcm[i],num[i]=0;
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;while(t--)
    T::solve();

}
