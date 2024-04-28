#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LRP int L=1,int R=N-1,int p=1
#define LS L,mid,p<<1
#define RS mid+1,R,p<<1|1
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e6+5;
    int n,m,A[N],res[N];
    int rd()
    {
        int res=0,f=1;char c;
        do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
        while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
        return res*f;
    }
    struct Query
    {
        int l,r,id;
        void input(int i)
        {
            l=rd();r=rd();id=i;
        }
        bool operator <(const Query &_)const
        {
            return r<_.r;
        }
    }Q[N];
    int T[N<<2];
    void Build(LRP)
    {
        if(L==R)return T[p]=-1,void();
        int mid=L+R>>1;
        T[p]=-1;
        Build(LS),Build(RS);
    }
    void Update(int x,int y,LRP)
    {
        if(L==R)
        {
            T[p]=y;
            return ;
        }
        int mid=L+R>>1;
        if(x<=mid)Update(x,y,LS);
        else Update(x,y,RS);
        T[p]=min(T[p<<1],T[p<<1|1]);
    }
    int Query(int x,LRP)
    {
        if(L==R)return L;
        int mid=L+R>>1;
        if(T[p<<1]<x)return Query(x,LS);
        return Query(x,RS);
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)A[i]=rd();
        cin>>m;
        for(int i=1;i<=m;++i)Q[i].input(i);
        sort(Q+1,Q+m+1);
        int now=1;
        for(int i=1;i<=m;++i)
        {
            int L=Q[i].l,R=Q[i].r;
            while(now<=R)Update(A[now]+1,now),++now;
            res[Q[i].id]=Query(L)-1;
        }
        for(int i=1;i<=m;++i)
            cout<<res[i]<<"\n";
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
