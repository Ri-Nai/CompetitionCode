#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,tot,fa[N];
    int last[N];
    map<int,int>mp;
    struct PR
    {
        int u,v,w;
        void output()
        {
            cout<<u<<' '<<v<<' '<<w<<'\n';
        }
    };
    vector<PR>ans;
    int find(int u)
    {
        return u==fa[u]?u:(fa[u]=find(fa[u]));
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;
            int x;cin>>x;
            while(x--)
            {
                int y;
                cin>>y;
                if(!mp[y])mp[y]=++tot;
                // E[mp[y]].push_back(x);
                // cout<<y<<'\n';
                int id=mp[y];
                if(last[id])
                {
                    int u=find(i),v=find(last[id]);
                    if(u!=v)
                    {
                        fa[u]=v;
                        ans.push_back((PR){last[id],i,y});
                    }
                }
                last[id]=i;
            }
        }
        if(ans.size()!=n-1)cout<<"impossible\n";
        else for(auto x:ans)x.output();
        // for(int i=1;i<=
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
