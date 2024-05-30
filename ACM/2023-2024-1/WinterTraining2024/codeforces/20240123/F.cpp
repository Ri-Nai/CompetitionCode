#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,m,dis[N],pre[N];
    char prec[N];
    vector<pair<int,char> >E[N];
    // string ans

    struct Edge
    {
        int u,v;
        char w;
        Edge(int _,int __,char ___){u=_,v=__,w=___;}
        bool operator <(const Edge&_)const
        {
            return w<_.w;
        }
    };
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=m;++i)
        {
            int u,v;char w;
            cin>>u>>v>>w;
            E[u].push_back({v,w});
            E[v].push_back({u,w});
        }
        queue<vector<int> >Q;
        pre[1]=-1;
        for(int i=2;i<=n;++i)
            dis[i]=1e9;
        Q.push(vector<int>(1,1));
        while(!Q.empty())
        {
            auto v=Q.front();
            Q.pop();
            vector<Edge>now;
            for(int u:v)for(auto [v,w]:E[u])now.push_back({u,v,w});
            sort(now.begin(),now.end());
            for(int i=0;i<now.size();++i)
            {
                int j=i;
                vector<int>nxt;
                while(j<now.size() and now[j].w==now[i].w)
                    ++j;
                --j;
                for(int k=i;k<=j;++k)
                {
                    auto [u,v,w]=now[k];
                    if(dis[v]<=dis[u]+1)continue;
                    dis[v]=dis[u]+1;
                    pre[v]=u;
                    prec[v]=w;
                    nxt.push_back(v);
                }
                Q.push(nxt);
                i=j;
            }
        }
        int x=n;
        vector<int>ans;
        string res;
        while(~x)
        {
            // if(pre[x]==0)End("-1");
            ans.push_back(x);
            if(x!=1)res+=prec[x];
            x=pre[x];
        }
        cout<<dis[n]<<'\n';
        reverse(ans.begin(),ans.end());
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
        reverse(res.begin(),res.end());
        cout<<res<<'\n';
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
