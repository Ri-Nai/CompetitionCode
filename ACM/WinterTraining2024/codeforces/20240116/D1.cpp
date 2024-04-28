#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=2e5+5,mod=1e9+7;
    const int M=2e3+5;
    int A[N],Q,sz,num;
    int dp[M][20],f[20],tmp[20];
    void DP(int l,int r)
    {
        for(int j=l;j<=r;++j)
        {
            for(int k=0;k<m;++k)
            {
                int now=k+A[j];now%=m;
                tmp[now]=(f[now]+f[k])%mod;
            }
            for(int k=0;k<m;++k)f[k]=tmp[k];
        }
    }
    void solve()
    {
        cin>>n>>m;
        sz=sqrt(n);
        num=n/sz;
        for(int i=0;i<=num;++i)dp[i][0]=1;
        for(int i=1;i<=n;++i)
            cin>>A[i],A[i]%=m;
        for(int i=1;i<=n;++i)
        {
            int p=i/sz;
            for(int j=0;j<m;++j)
            {
                int now=j+A[i];now%=m;
                tmp[now]=(dp[p][now]+dp[p][j])%mod;
            }
            for(int j=0;j<m;++j)dp[p][j]=tmp[j];
        }
        cin>>Q;
        for(int i=1;i<=Q;++i)
        {
            int l,r;
            cin>>l>>r;
            int pl=l/sz,pr=r/sz;
            for(int j=0;j<m;++j)f[j]=0;
            f[0]=1;
            if(pl==pr)
            {
                DP(l,r);

            }
            else
            {
                DP(l,(pl+1)*sz-1);
                DP(pr*sz,r);
            }
            printf("%d\n",f[0]);
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';

    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
