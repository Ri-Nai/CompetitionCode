#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
#define LRP int L=1,int R=n,int p=1
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n;
    ll T[N<<2],lz[N<<2];
    int A[N],L[N],R[N];
    void upd(int p)
    {
        T[p]=max(T[p],lz[p]);
        lz[p<<1]=max(lz[p<<1],lz[p]);
        lz[p<<1|1]=max(lz[p<<1|1],lz[p]);
        lz[p]=0;
    }
    void Update(int l,int r,ll x,LRP)
    {
        if(L==l and r==R)
        {
            lz[p]=max(lz[p],x);
            return ;
        }
        upd(p);
        int mid=(L+R)>>1;
        if(l>mid)Update(l,r,x,mid+1,R,p<<1|1);
        else if(r<=mid)Update(l,r,x,L,mid,p<<1);
        else Update(l,mid,x,L,mid,p<<1),Update(mid+1,r,x,mid+1,R,p<<1|1);
    }
    ll Query(int x,LRP)
    {
        upd(p);
        if(L==R)return T[p];
        int mid=(L+R)>>1;
        if(x>mid)return Query(x,mid+1,R,p<<1|1);
        else return Query(x,L,mid,p<<1);
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        for(int i=2;i<=n;++i)
            cin>>L[i]>>R[i];
            // cout<<"A\n";
        for(int i=n;i>1;--i)
        {
            ll now=Query(i);
            if(i!=n and !now)continue;
            Update(L[i],R[i],now+A[i]);
            // for(int j=1;j<=n;++j)
            //     cout<<Query(j)<<' ';
            // cout<<'\n';
        }
        cout<<A[1]+Query(1)-n+1<<'\n';
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
