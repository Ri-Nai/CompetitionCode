#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e6+5;
    int n,m,sz;
    int A[N],cnt[N],num[N];
    int res[N];
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
        int pl,pr;
        void input(int i)
        {
            l=rd();r=rd();id=i;
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
        if(!cnt[t]++)++num[t/sz];
    }
    void Del(int t)
    {
        if(!--cnt[t])--num[t/sz];
    }
    int Query()
    {
        for(int i=0;i<=sz;++i)
            if(num[i]!=sz)for(int j=sz*i;j<sz*(i+1);++j)
                if(!cnt[j])return j;
    }
    void solve()
    {
        cin>>n;
        sz=sqrt(n)+1;
        for(int i=1;i<=n;++i)A[i]=rd();
        cin>>m;
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
            res[Q[i].id]=Query();
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
