#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m1,m2;
    const int N=3005;
    typedef tuple<int,int,int> tp;
    vector<tp>T1,T2;
    vector<pair<int,int>>E[N];
    bool SPFA()
    {
        queue<int>Q;
        vector<int>dis(n+1,11451419),in(n+1,0);
        vector<bool>vis(n+1,0);
        dis[0]=0;
        vis[0]=in[0]=1;
        Q.push(0);
        while(!Q.empty())
        {
            int u=Q.front();
            vis[u]=0;
            Q.pop();
            for(auto [v,w]:E[u])
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    // if(dis[v]<0)return 0;
                    if(!vis[v])
                    {
                        if(++in[v]==n+2)return 0;
                        vis[v]=1;
                        Q.push(v);
                    }
                }
        }
        return 1;
    }
    bool check(int s)
    {
        for(int i=0;i<=n;++i)E[i].clear();
        for(int i=0;i<n;++i)E[i+1].push_back({i,0});
        for(int i=0;i<n;++i)E[i].push_back({i+1,1});
        for(auto [l,r,k]:T1)
            E[r].push_back({l-1,-k});
        for(auto [l,r,k]:T2)
            E[l-1].push_back({r,s-k});
        E[0].push_back({n,s});
        E[n].push_back({0,-s});

        return SPFA();
    }
    void solve()
    {
        cin>>n>>m1>>m2;
        T1.clear();T2.clear();
        for(int i=1,L,R,K;i<=m1;++i)
            cin>>L>>R>>K,T1.push_back({L,R,K});
        for(int i=1,L,R,K;i<=m2;++i)
            cin>>L>>R>>K,T2.push_back({L,R,K});
        int l=0,r=n,res=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid))res=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<res<<'\n';
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
