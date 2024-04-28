#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8,mod=998244353;
typedef long long ll;
ll n;
int A[N];
namespace P60
{
    void Solve()
    {
        ll f1=1,f2=1;
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            ans=(ans+f2*f2%mod)%mod;
            ll t=f2;
            f2=f1;
            f1=(t+f1)%mod;
        }
        cout<<ans<<'\n';
    }
}
namespace P100
{
    struct Mat
    {
        ll A[2][2];
        Mat(int k)
        {
            A[0][0]=A[1][1]=k;
            A[0][1]=A[1][0]=0;
        }
        Mat operator *(const Mat &_)const
        {
            Mat res(0);
            for(int i=0;i<=1;++i)
                for(int j=0;j<=1;++j)
                    for(int k=0;k<=1;++k)
                        res.A[i][j]=(res.A[i][j]+A[i][k]*_.A[k][j]%mod)%mod;
            return res;

        }
    };
    Mat Pow(Mat p,ll n)
    {
        Mat res(1);
        while(n)
        {
            if(n&1)res=res*p;
            p=p*p;
            n>>=1;
        }
        return res;
    }
    void Solve()
    {
        Mat F(0),P(0);
        F.A[0][0]=F.A[0][1]=1;
        P.A[0][0]=P.A[0][1]=P.A[1][0]=1;
        Mat T=F*Pow(P,n-1);
        cout<<T.A[0][0]*T.A[0][1]%mod<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    if(n<=1000000)P60::Solve();
    else P100::Solve();
}
/*
1 1 2 3 5
1 1 4 9
1 2 6 15

1 1 0    1 1 0
0 0 0    1 0 1
0 0 0    0 0 1
*/
