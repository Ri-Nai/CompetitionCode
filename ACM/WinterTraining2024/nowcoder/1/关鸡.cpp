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
    const int N=1e5+5;
    Pr A[N];
    int n;
    void solve()
    {
        cin>>n;
        int cnt=0;
        map<Pr,int>mp;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            A[i]={y,x};
            mp[A[i]]=1;
        }
        sort(A+1,A+n+1);
        int res1=0,res2=0;
        for(int i=1;i<=n;++i)
        {
            auto [x,y]=A[i];
            if(x<=-1)
            {
                if(mp[{x,3-y}] or mp[{x+1,3-y}])
                    res1=max(res1,2);
                else res1=max(res1,1);
            }
            else if(x>=1)
            {
                if(mp[{x,3-y}] or mp[{x-1,3-y}])
                    res2=max(res2,2);
                else res2=max(res2,1);
            }
            else res1=max(1,res1),res2=max(res2,1);
        }
        int ans=min(3,4-res1-res2);
        ans=min(ans,3-mp[{1,1}]-mp[{-1,1}]-mp[{0,2}]);
        cout<<ans<<'\n';
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
