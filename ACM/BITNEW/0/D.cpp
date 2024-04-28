#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=2e5+3;
    int n,A[M],fa[M],sz[M],id[M];
    int mx=0,k,mxsz,now,small;
    bool cmp(int a,int b)
    {
        return A[a]<A[b];
    }
    int find(int x)
    {
        return x==fa[x]?x:(fa[x]=find(fa[x]));
    }
    void opr(int x)
    {
        sz[x]=1;++now;++small;
        if(x-1>=1 and sz[find(x-1)])
        {
            if(sz[fa[x-1]]<mxsz)--small;
            sz[fa[x-1]]+=sz[fa[x]],fa[x]=fa[x-1],--now;
        }
        if(x-1>=1 and sz[find(x+1)])
        {
            if(sz[fa[x+1]]<mxsz)--small;
            sz[fa[x+1]]+=sz[fa[x]],fa[x]=fa[x+1],--now;
        }
        if(sz[fa[x]]>mxsz)
            small=now-1,mxsz=sz[fa[x]];
        else if(sz[fa[x]]==mxsz)--small;
        // cout<<x<<' '<<now<<' '<<small<<'\n';
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[fa[i]=id[i]=i],sz[i]=0;
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=n;++i)
        {
            opr(id[i]);
            while(A[id[i+1]]==A[id[i]])
                opr(id[i+1]),++i;
            if(small==0 and now>mx)
            {
                // cout<<now<<' '<<mx<<' '<<A[id[i]]<<'\n';
                // cout<<sz[fa[id[i]]]<<'\n';
                mx=now,k=A[id[i]]+1;
            }
        }
        cout<<k<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
