#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=5e4+5;
    int n,m,k,sz;
    int A[N],cnt[N];
    ll ans,res[N];
    struct Query
    {
        int l,r,id;
        int pl,pr;
        void input(int i)
        {
            cin>>l>>r;id=i;
            pl=(l-1)/sz+1;
            pr=(r-1)/sz+1;
        }
        bool operator <(const Query &_)const
        {
            if(pl==_.pl)
            {
                if(pr==_.pr)return r<_.r;
                return pr<_.pr;
            }
            return pl<_.pl;
        }
    }Q[N];
    void Add(int t)
    {
        ans+=cnt[t]*2+1;
        ++cnt[t];
    }
    void Del(int t)
    {
        ans-=cnt[t]*2-1;
        --cnt[t];
    }
    void solve()
    {
        cin>>n>>m>>k;
        sz=sqrt(n)+1;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=m;++i)Q[i].input(i);
        sort(Q+1,Q+m+1);
        int l=1,r=0;
        for(int i=1;i<=m;++i)
        {
            int L=Q[i].l,R=Q[i].r;
            while(l>L)Add(A[--l]);
            while(r<R)Add(A[++r]);
            while(l<L)Del(A[l++]);
            while(r>R)Del(A[r--]);
            res[Q[i].id]=ans;
        }
        for(int i=1;i<=m;++i)
            cout<<res[i]<<"\n";
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
