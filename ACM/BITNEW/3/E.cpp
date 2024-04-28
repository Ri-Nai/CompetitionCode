#include<bits/stdc++.h>
using namespace std;
#define End(X) return cout<<X<<'\n',void()
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    const int N=2e5+5,M=N*5;
    int n,m,A[N],B[N];
    int t1,t2,t3,t4;
    int dis[N];
    // int W[M],V[M],D[M],nxt[M],tot,head[N];
    struct node
    {
        int v,w,bg,d;
    };
    struct Pr
    {
        int first,second;
        Pr(int _,int __){first=_,second=__;}
        bool operator < (const Pr&_)const
        {
            return first>_.first;
        }
    };
    vector<node>E[N];
    bool mark[N];
    inline void Add(const int &u,const int &v,const int &w,const int &bg,const int &d)
    {
        E[u].push_back((node){v,w,bg,d});
    }
    bool check(int asleep)
    {
        memset(dis,-1,sizeof dis);
        memset(mark,0,sizeof mark);
        dis[1]=t1+asleep;
        priority_queue<Pr>Q;
        Q.push(Pr(dis[1],1));
        while(!Q.empty())
        {
            int u=Q.top().second;
            if(mark[u])continue;
            mark[u]=1;
            Q.pop();
            for(auto t:E[u])
            {
                int v=t.v,w=t.w;
                int now,bg=t.bg;
                if(dis[u]<bg)now=bg;
                else now=bg+((dis[u]-1-bg)/t.d+1)*t.d;
                if(!~dis[v] or dis[v]>now+w)
                    dis[v]=now+w,Q.push(Pr(dis[v],v));
            }
        }
        return ~dis[n] and dis[n]<=t2;
    }
    void solve()
    {
        t1=rd();t2=rd();
        t1+=rd();t2-=rd();
        n=rd(),m=rd();
        for(int i=1;i<=m;++i)
        {
            int k=rd(),d=rd();
            int bg=k*d;
            for(int i=1;i<=k;++i)A[i]=rd();
            for(int i=1;i<k;++i)B[i]=rd();
            for(int i=1;i<k;++i)
                Add(A[i],A[i+1],B[i],bg,d),bg+=B[i];
            bg=k*d;
            for(int i=k-1;i>=1;--i)
                Add(A[i+1],A[i],B[i],bg,d),bg+=B[i];
        }
        int l=0,r=1e9,ans=-1;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid))
                ans=mid,l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    T::solve();
}
