#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),k=rd();
        vector<int>A(n+1);
        for(int i=1;i<=n;++i)
            A[i]=rd();
        auto Max=[&]()
        {
            ll mx=-1e18;
            ll now=0;
            for(int i=1;i<=n;++i)
            {
                now+=A[i];
                mx=max(mx,now);
                now=max(now,0ll);
            }
            return mx;
        };
        if(k==0)cout<<Max()<<'\n';
        else
        {
            vector<int>B=A;
            ll ans=-1e18;
            for(int i=1;i<n;++i)
            {
                A=B;
                swap(A[i],A[i+1]);
                ans=max(ans,Max());
            }
            cout<<ans<<'\n';
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
