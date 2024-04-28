#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        ll ans=0;
        int n=rd(),m=rd();
        vector<int>A(n+1),B(n+1);
        for(int i=1;i<=n;++i)
            A[i]=rd(),B[i]=rd();
        auto check=[&](int now)
        {
            ll res=0;
            for(int j=1;j<=n;++j)
                if((B[j]|now)==now)res+=A[j];
            ans=max(ans,res);
        };
        check(m);
        for(int i=0;i<30;++i)
        {
            int k=1<<i;
            if(k&m)check((m-k)|(k-1));
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
