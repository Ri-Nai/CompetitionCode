#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int P=1e9+7;
namespace T
{
    struct Matrix
    {
        ll M[5][5];
        Matrix(){memset(M,0,sizeof M);}
        Matrix operator *(const Matrix &_)
        {
            Matrix A;
            for(int i=1;i<=4;++i)
                for(int j=1;j<=4;++j)
                    for(int k=1;k<=4;++k)
                        (A.M[i][j]+=1ll*M[i][k]*_.M[k][j]%P)%=P;
            return A;
        }
    }A,X;
    Matrix Pow(Matrix now,long long n)
    {
        Matrix res;
        res.M[1][1]=res.M[2][2]=res.M[3][3]=res.M[4][4]=1;
        while(n)
        {
            if(n&1)res=res*now;
            now=now*now;
            n>>=1;
        }
        return res;
    }
    void solve()
    {
        int a,b,c;
        ll n;
        cin>>a>>b>>c>>n;
        if(c==0)n=3;
        if(b==0)n=2;
        if(a==0)n=1;
        A.M[1][1]=a;
        A.M[1][2]=b;
        A.M[1][3]=c;
        X.M[2][1]=X.M[1][4]=X.M[2][3]=
        X.M[4][4]=X.M[3][2]=X.M[3][3]=1;
        A=A*Pow(X,n);
        cout<<A.M[1][4]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
