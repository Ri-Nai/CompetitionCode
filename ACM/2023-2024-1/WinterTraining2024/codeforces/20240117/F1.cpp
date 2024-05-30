#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=305;
    int n,m;
    int A[N],res[N],id[N],in[N];
    bool mark[N];
    struct Edge
    {
        int to,id,val;
        bool operator <(const Edge &_)const
        {
            if(id==_.id)
            {
                if(to==_.to)return val<_.val;
                return to<_.to;
            }
            return id<_.id;
        }
    };
    struct Point
    {
        int id,val;
        bool operator <(const Point &_)const
        {
            if(val==_.val)return id<_.id;
            return val>_.val;
        }
    };
    set<Edge>E[N];
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>A[id[i]=i],in[i]=0,E[i].clear();
        for(int i=1;i<=m;++i)
        {
            mark[i]=0;
            int u,v;
            cin>>u>>v;
            E[u].insert((Edge){v,i,1});
            E[v].insert((Edge){u,i,0});
            ++in[u];++in[v];
        }
        set<Point>S;
        for(int i=1;i<=n;++i)S.insert((Point){i,A[i]-in[i]});
        for(int i=1;i<=m;++i)
        {
            int u=S.begin()->id;
            // cout<<S.size()<<'\n';
            if(E[u].size()==0)
            {
                S.erase(S.begin());
                --i;
                continue;
            }
            auto tt=E[u].begin();
            int tv=tt->to;
            for(auto it=E[u].begin();it!=E[u].end();++it)
            {
                int v=it->to;
                if(A[v]-in[v]<A[tv]-in[tv])
                    tt=it,tv=v;
            }
            auto now=S.find((Point){tv,A[tv]-in[tv]});
            res[tt->id]=tt->val;
            E[tv].erase(E[tv].find((Edge){u,tt->id,(tt->val)^1}));
            E[u].erase(tt);
            S.erase(now);
            --in[u];--in[tv];
            --A[u];
            S.insert((Point){tv,A[tv]-in[tv]});
        }
        int ans=0;
        for(int i=1;i<=n;++i)
            ans+=max(0,-A[i]);
        cout<<ans<<'\n';
        for(int i=1;i<=m;++i)
            cout<<res[i];
        cout<<'\n';
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
/**
总共有n个点
每个点有A[i]的权值
所以对每个点来说
A[i


*/
