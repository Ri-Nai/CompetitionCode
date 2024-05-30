#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int P=1e9+7;
    void Add(ll &x,ll y)
    {
        y%=P;
        x+=y;
        x%=P;
    }
    struct Mat
    {
        ll M[3][3];
        Mat(bool p)
        {
            for(int i=1;i<=2;++i)
                for(int j=1;j<=2;++j)
                    M[i][j]=p?(i==j):0;
        }
        Mat operator *(const Mat&_)
        {
            Mat res(0);
            for(int i=1;i<=2;++i)
                for(int j=1;j<=2;++j)
                    for(int k=1;k<=2;++k)
                        Add(res.M[i][j],M[i][k]*_.M[k][j]);
            return res;
        }
        void equal(const Mat&_)
        {
            for(int i=1;i<=2;++i)
                for(int j=1;j<=2;++j)
                    M[i][j]=_.M[i][j];

        }
    };
    Mat Pow(Mat X,ll p)
    {
        Mat res(1);
        while(p)
        {
            if(p&1)res.equal(res*X);
            X.equal(X*X);
            p>>=1;
        }
        return res;
    }
    void solve()
    {
        ll x,y,n;
        cin>>x>>y>>n;
        x%=P,y%=P;
        Mat P(0),Q(0);
        P.M[1][1]=x;
        P.M[1][2]=y;
        Q.M[1][2]=Q.M[2][1]=Q.M[2][2]=1;
        if(n==1)End(x);
        if(n==2)End(y);
        End((P*Pow(Q,n-1)).M[1][1]);
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
