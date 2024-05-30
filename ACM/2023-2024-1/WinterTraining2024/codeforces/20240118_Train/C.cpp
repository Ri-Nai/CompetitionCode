#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    ull k1,k2;
    const int N=1e5+5;
    const ull mod=1e9+7;
    ull Rand()
    {
        ull k3=k1,k4=k2;
        k1=k4;
        k3^=k3<<23;
        k2=k3^k4^(k3>>17)^(k4>>26);
        return k2+k4;
    }
    int n,m,u[N],v[N];
    int fa[N],id[N];
    ull w[N];
    bool cmp(int a,int b)
    {
        return w[a]<w[b];
    }
    int find(int u)
    {
        // return u==fa[u]?u:(fa[u]=find(fa[u]));
        if(u==fa[u])return u;
        return fa[u]=find(fa[u]);
    }
    ull ans;
    bool Kruskal()
    {
        int cnt=0;
        for(int i=1;i<=m;++i)
        {
            int p=id[i];
            // if(w[id[i]]>w[id[i+1]])cout<<"AAA\n";
            int x=u[p],y=v[p];
            ull z=w[p];
            if(find(x)!=find(y))
            {
                fa[find(x)]=y;
                ++cnt;
                ans=(ans+z%mod)%mod;
                if(cnt==n-1)return 1;
            }
        }
        return 0;
    }
    void gen()
    {
        ans=0;
        cin>>n>>m>>k1>>k2;
        for(int i=1;i<=m;++i)id[i]=i;
        for(int i=1;i<=m;++i)
            u[i]=Rand()%n+1,
            v[i]=Rand()%n+1,
            w[i]=Rand();
        for(int i=1;i<=n;++i)fa[i]=i;
        sort(id+1,id+m+1,cmp);
    }
    void solve()
    {
        gen();
        if(!Kruskal())cout<<"0\n";
        else cout<<ans<<'\n';
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
