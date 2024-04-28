#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int K;
    const int N=2e5+5;
    int fa[N],cost[N],n;
    int Build(int now,int f)
    {
        int p=++n;
        fa[p]=f;
        if(now==1)return cost[p]=1;
        if(now==2)
        {
            cost[p]=1;
            fa[++n]=p;
            cost[n]=1;
            return 1;
        }
        if(now&1)return cost[p]=Build(now-1,p);
        cost[p]=Build(2,p)+Build(now>>1,p)+1;
        return cost[p]-1;
    }
    void solve()
    {
        cin>>K;n=0;
        Build(K,1);
        if(K==1)End("2\n1\n2 1");
        cout<<n<<'\n';
        for(int i=2;i<=n;++i)cout<<fa[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=n;++i)cout<<cost[i]<<' ';
        cout<<'\n';
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
