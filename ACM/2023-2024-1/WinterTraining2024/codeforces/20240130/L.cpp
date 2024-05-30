#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    ll A[20][20];
    int B[20];
    ll gcd(ll a,ll b)
    {
        if(a<0 and b<0)return gcd(-a,-b);
        if(a<0)return gcd(-a,b);
        if(b<0)return gcd(a,-b);
        return b?gcd(b,a%b):a;
    }
    bool Guass()
    {
        for(int i=1;i<=5;++i)
            for(int j=i+1;j<=5;++j)
            {
                ll g=gcd(A[i][i],A[j][i]);
                ll k1=A[j][i]/g;
                ll k2=A[i][i]/g;
                for(int k=i;k<=6;++k)
                    A[j][k]=k2*A[j][k]-k1*A[i][k];
            }
        for(int i=5;i>=1;--i)
            for(int j=i-1;j>=1;--j)
            {
                ll g=gcd(A[i][i],A[j][i]);
                ll k1=A[j][i]/g;
                ll k2=A[i][i]/g;
                for(int k=j;k<=6;++k)
                    A[j][k]=k2*A[j][k]-k1*A[i][k];
            }
        for(int i=1;i<=5;++i)
        {
            if(A[i][i]==0)return 0;
            if(A[i][i]<0)A[i][i]=-A[i][i],A[i][6]=-A[i][6];
            ll g=gcd(A[i][i],A[i][6]);
            if(g!=A[i][i])return 0;
            A[i][6]/=g;
            if(A[i][6]>100 or A[i][6]<-100)return 0;
        }
        return 1;
    }
    void solve()
    {
        for(int i=1;i<=5;++i)
            cin>>B[i];
        for(int i=0;i<3*3*3*3*3;++i)
        {
            for(int j=1;j<=5;++j)
            {
                int t=1;
                for(int k=1;k<=5;++k)
                {
                    A[j][k]=t;
                    t=t*j;
                }
            }
            int x=i;
            for(int j=1;j<=5;++j)
            {
                int t=x%3;
                A[j][6]=B[j];
                if(t==1)--A[j][6];
                if(t==2)++A[j][6];
                x/=3;
            }
            if(Guass())
            {
                // cout<<i<<'\n';
                for(int j=1;j<=5;++j)
                    cout<<A[j][6]<<' ';
                cout<<'\n';
                return ;
            }
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
