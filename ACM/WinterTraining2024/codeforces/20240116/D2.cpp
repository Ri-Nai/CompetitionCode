#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
#define LRP int L=1,int R=n,int p=1
#define LSON L,mid,p<<1
#define RSON mid+1,R,p<<1|1
bool Nai;
namespace T
{
    const int mod=1e9+7;
    const int N=2e5+5;
    int n,m;
    struct Node
    {
        int A[20];
        Node(){memset(A,0,sizeof A);}
        Node operator +(const Node &_)
        {
            Node res;
            for(int i=0;i<m;++i)
                for(int j=0;j<m;++j)
                    res.A[(i+j)%m]=(res.A[(i+j)%m]+1ll*A[i]*_.A[j]%mod)%mod;
            return res;
        }
    }T[N<<2];
    int A[N];
    Node Build(LRP)
    {
        if(L==R)
        {
            ++T[p].A[0];
            ++T[p].A[A[L]%m];
            return T[p];
        }
        int mid=L+R>>1;
        return (T[p]=Build(LSON)+Build(RSON));
    }
    Node Query(int l,int r,LRP)
    {
        if(l==L and R==r)return T[p];
        int mid=L+R>>1;
        if(r<=mid)return Query(l,r,LSON);
        if(l>mid)return Query(l,r,RSON);
        return Query(l,mid,LSON)+Query(mid+1,r,RSON);
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>A[i];
        int q;cin>>q;
        Build();
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            printf("%d\n",Query(l,r).A[0]);
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
