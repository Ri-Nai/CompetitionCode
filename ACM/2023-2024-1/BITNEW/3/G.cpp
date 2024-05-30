#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ull;
#define End(X) return cout<<X<<'\n',void()
/*

namespace T
{
    const int M=405;
    int n,m;
    int mstt;
    double dp[2][1<<21];
    double ans[M];
    int count(int stt)
    {
        int ans=0;
        for(int i=0;i<n;++i)
            ans+=!!((3<<i*3)&stt);
        return ans;
    }
    int change(int stt,int id)
    {
        int now=((7<<id*3)&stt)>>id*3;
        int res=0;
        if(now&4)
        {
            now^=4;
            res|=now<<id*3;
            for(int i=0;i<n;++i)
                if(i!=id and (stt&(3<<i*3)))
                    res|=((3<<i*3)&stt)|(4<<i*3);
            return res;
        }
        --now;
        stt^=(7<<id*3)&stt;
        stt|=now<<id*3;
        return stt;
    }
    void solve()
    {
        cin>>n>>m;
        mstt=(1<<3*n)-1;//(1<<21)
        int now=0,lst=0;
        ans[0]=0;
        dp[0][mstt]=1;
        // for(int i=1;i<=mstt;++i)
        // {
        //     for(int j=0;j<n;++j)
        //         if((7<<j*3)&i)
        //             cout<<i<<' '<<change(i,j)<<'\n';
        // }
        // cout<<change(1,0)<<'\n';
        for(int i=1;i<=400;++i)
        {
            lst=now;
            now^=1;
            // cout<<now<<' '<<lst<<'\n';
            for(int p=0;p<=mstt;++p)dp[now][p]=0;
            for(int p=0;p<=mstt;++p)
            {
                int cnt=count(p);
                if(dp[lst][p]!=0)cout<<i<<' '<<p<<' '<<dp[lst][p]<<'\n';
                for(int j=0;j<n;++j)
                {
                    if(!((3<<j*3)&p))continue;
                    int q=change(p,j);
                    // if(q==0)cout<<i<<' '<<p<<' '<<"!!!!!!!!\n";
                    // cout<<q<<"aaa\n";
                    dp[now][q]+=dp[lst][p]*(1./cnt);
                }
            }
            dp[now][0]+=dp[lst][0];
            ans[i]=dp[now][0];
        }
        for(int x;m--;)cin>>x,cout<<ans[x]<<'\n';
    }
}
*/
namespace P
{
    const int M=405;
    const int P=80000;
    double dp[2][8][P],ans[M];
    const int T[]={1,5,5*5,5*5*5,5*5*5*5,5*5*5*5*5,5*5*5*5*5*5,5*5*5*5*5*5*5};
    int n,m,mx=1,Cnt[P];
    inline bool in(int p,int i)
    {
        return p/T[i]%5;
    }
    void Solve()
    {
        cin>>n>>m;
        // mx=pow(5,n);
        for(int i=1;i<=n;++i)mx*=5;
        // mx=500000;
        // dp[0][0][mx-1]=1;
        // cout<<mx<<'\n';
        for(int i=0;i<mx;++i)
            for(int j=0;j<n;++j)
                Cnt[i]+=!!(i/T[j]%5);
        // cout<<"AAA\n";
        int now=0,lst=0;
        for(int i=0;i<n;++i)
            dp[0][i][mx-1]=1./n;
        for(int i=2;i<=400;++i)
        {
            lst=now,now^=1;
            for(int k=0;k<n;++k)
                for(int j=0;j<mx;++j)
                    dp[now][k][j]=0;
            for(int j=1;j<mx;++j)
                for(int b=0;b<n;++b)
                {
                    // if(!in(j,a))continue;
                    if(!in(j,b))continue;
                    for(int a=0;a<n;++a)
                    {
                        if(a!=b)dp[now][b][j]+=dp[lst][a][j]*1./Cnt[j];
                        else dp[now][b][j-T[b]]+=dp[lst][a][j]*1./Cnt[j];
                    }
                }
            for(int j=0;j<n;++j)
            {
                dp[now][j][0]+=dp[lst][j][0];
                ans[i]+=dp[now][j][0];
            }
            // cout<<"AAA\n";
        }
        // cout<<ans[10]<<'\n';
        for(int x;m--;)cin>>x,cout<<ans[x]<<'\n';
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
        // cout<<"AAA\n";
    // int t;cin>>t;while(t--)
    // T::solve();
    P::Solve();

}
