#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m,q;
    const int N=1e5+5;
    int A[N];
    vector<int>E[N];
    vector<int>P[N];
    int ans[N][101];
    void solve()
    {
        cin>>n>>m>>q;
        for(int i=1,x;i<=n;++i)
            cin>>x,P[x].push_back(i);
        for(int i=1,u,v;i<=m;++i)
        {
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for(int i=1;i<=100;++i)
        {
            queue<int>Q;
            for(int j=1;j<=n;++j)ans[j][i]=1e9;
            for(int p:P[i])ans[p][i]=0,Q.push(p);
            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                for(int v:E[u])
                    if(ans[v][i]>ans[u][i]+1)
                        ans[v][i]=ans[u][i]+1,Q.push(v);
            }
            if(i!=1)for(int j=1;j<=n;++j)
                ans[j][i]=min(ans[j][i],ans[j][i-1]);
        }
        for(int i=1,p,a;i<=q;++i)
        {
            cin>>p>>a;
            printf("%d\n",ans[p][a]==1e9?-1:ans[p][a]);
        }
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
