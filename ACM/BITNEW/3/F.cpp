#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e3+5;
    int n,m,B[M],C[M];
    int gcd(int a,int b)
    {
        return b?gcd(b,a%b):a;
    }
    void solve()
    {
        cin>>m;
        for(int i=1;i<=m;++i)cin>>B[i];
        for(int i=1;i<=m;++i)cin>>C[i];
        for(int n=1;n<=m;++n)
        {
            int res=1;
            for(int i=1;res and i<=n;++i)
            {
                bool flag=1;
                for(int a=i;flag and a<=m;a+=n)
                    for(int b=a+n;flag and b<=m;b+=n)
                            flag&=C[a]%gcd(B[a],B[b])==C[b]%gcd(B[a],B[b]);
                res&=flag;
            }
            if(res)End(n);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
