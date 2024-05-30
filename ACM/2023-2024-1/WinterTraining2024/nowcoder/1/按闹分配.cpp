#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
ll rd()
{
    ll res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd(),Q=rd(),tc=rd();
        vector<int>T(n+1);
        for(int i=1;i<=n;++i)T[i]=rd();
        sort(T.begin()+1,T.end());
        vector<ll>S(n+1);
        for(int i=1;i<=n;++i)S[i]=S[i-1]+T[i];
        auto Solve=[&](ll M)
        {
            int l=0,r=n,res=n;
            while(l<=r)
            {
                int mid=l+r>>1;
                ll SS=1ll*(n-mid)*tc;
                if(SS<=M)r=mid-1,res=mid;
                else l=mid+1;
            }
            cout<<S[res]+tc<<'\n';
        };
        for(int i=1;i<=Q;++i)Solve(rd());
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
