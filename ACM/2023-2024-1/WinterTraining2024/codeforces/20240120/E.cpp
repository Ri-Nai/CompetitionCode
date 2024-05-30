#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=1e5+5;
    struct Edge
    {
        int u,v,w,id;
        bool operator <(const Edge&_)const
        {
            return w<_.w;
        }
    };
    vector<Edge>E[N];
    int fa[N];
    int find(int u)
    {
        return u==fa[u]?u:(fa[u]=find(fa[u]));
    }
    int get(int x)
    {
        int l=0,r=x,res=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(1ll*mid*(mid+1)/2>=x)
                res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;
    }
    void solve()
    {
        cin>>n;
        vector<Edge>edges;
        for(int i=1;i<=n;++i)E[i].clear();
        for(int i=1;i<n;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            E[u].push_back((Edge){u,v,w,i});
            E[v].push_back((Edge){v,u,w,i});
        }
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;
            sort(E[i].begin(),E[i].end());
            int limit=E[i].size()*2;
            for(int j=0;j<E[i].size();++j)
            {
                for(int k=j+1;k<E[i].size();++k)
                {
                    int u=E[i][j].id;
                    int v=E[i][k].id;
                    int w=E[i][j].w+E[i][k].w;
                    edges.push_back((Edge){u,v,w,0});
                    if(!--limit)break;
                }
                if(!limit)break;
            }
        }
        sort(edges.begin(),edges.end());
        int cnt=0;
        ll res=0;
        // cout<<edges.size()<<"***\n";
        for(auto [u,v,w,id]:edges)
        {
            // cout<<u<<' '<<v<<'\n';
            u=find(u);
            v=find(v);
            // cout<<u<<' '<<v<<'\n';
            // cout<<"*************\n";
            if(u==v)continue;
            fa[u]=v;
            res+=w;
            if(++cnt==n-1)break;
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
