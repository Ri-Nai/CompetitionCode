#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=5e5+5;
    int rd()
    {
        int res=0,f=1;char c;
        do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
        while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
        return res*f;
    }
    void solve()
    {
        int n=rd(),m=rd();
        vector<array<int,4>>P(1);
        vector<vector<pair<int,int>>>E(n+1);
        vector<int>ans,one,two;
        vector<int>dfn(n+1),low(n+1);
        vector<int>stk(n+1),blg(n+1);
        vector<int>in(n+1);
        int tot=0,top=0,blk=0;
        for(int i=1;i<=m;++i)
        {
            int l=rd(),x=rd(),r=rd(),y=rd();
            if(x>y)swap(x,y),swap(l,r);
            P.push_back({l,x,r,y});
            if(y==1)one.push_back(i);
            else if(x==2)two.push_back(i);
            else E[l].emplace_back(r,i);
        }
        auto tarjan=[&](auto self,int u)->void
        {

            dfn[stk[++top]=u]=low[u]=++tot;
            in[u]=1;
            for(auto [v,id]:E[u])
            {
                if(!dfn[v])self(self,v),low[u]=min(low[u],low[v]);
                else if(in[v])low[u]=min(low[u],dfn[v]);
            }
            if(dfn[u]==low[u]&&++blk)
            {
                int v;
                do blg[v=stk[top--]]=blk,in[v]=0;while(u^v);
            }
        };
        for(int i=1;i<=n;++i)
            if(!dfn[i])tarjan(tarjan,i);
        for(int u=1;u<=n;++u)
            for(auto [v,id]:E[u])
                if(blg[u]^blg[v])++in[blg[v]];
        vector<int>res;
        vector<bool>vis(n+1);
        auto dfs=[&](auto self,int u)->void
        {
            vis[u]=1;
            for(auto [v,id]:E[u])
            {
                res.push_back(id);
                if(!vis[v])self(self,v);
            }
        };
        for(int t:two)
        {
            auto [l,x,r,y]=P[t];
            if(!vis[l]&&!in[blg[l]])dfs(dfs,l);
            if(!vis[r]&&!in[blg[r]])dfs(dfs,r);
        }
        for(int i=1;i<=n;++i)
            if(!vis[i]&&!in[blg[i]])dfs(dfs,i);
        reverse(res.begin(),res.end());
        ans.insert(ans.end(),one.begin(),one.end());
        ans.insert(ans.end(),res.begin(),res.end());
        ans.insert(ans.end(),two.begin(),two.end());
        vector<int>A(n+1);
        for(int p:ans)
        {
            auto [l,x,r,y]=P[p];
            A[l]=x,A[r]=y;
        }
        int S=accumulate(A.begin(),A.end(),0);
        cout<<S<<'\n';
        for(int i:ans)cout<<i<<' ';
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
