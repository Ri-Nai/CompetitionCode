#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
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
        int n=rd();
        vector<int>A(n+2);
        vector<ll>dp(n+2);
        vector<vector<int>>has(n+2);
        for(int i=1;i<=n;++i)
            A[i]=rd();
        for(int i=1;i<=n+1;++i)
        {
            for(int j=1;j<=i;++j)
            {
                ll t=dp[j-1]+(i-j)*(i-j);
                if(t>dp[i])dp[i]=t,has[i]=has[j-1];
            }
            dp[i]+=A[i];
            has[i].push_back(i);
        }
        vector<pair<int,int>>op;
        auto change=[&](auto self,int l,int r)->void
        {
            if(r<l)return ;
            for(int i=r-1;i>=l;--i)
            {
                self(self,l,i);
                if(i!=l)op.emplace_back(l,i-1);
            }
            op.emplace_back(l,r);

        };
        auto convert=[&](int l,int r)
        {
            for(int i=l;i<=r;++i)
                if(A[i])op.push_back({i,i});
            change(change,l,r);
        };
        int l=1;
        for(int r:has[n+1])
        {
            convert(l,r-1);
            l=r+1;
        }
        int m=op.size();
        printf("%lld %d\n",dp[n+1],m);
        for(auto [x,y]:op)
        {
            printf("%d %d\n",x,y);
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
