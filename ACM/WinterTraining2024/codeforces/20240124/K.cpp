#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=1e5+5;
    int A[N],B[N],D[N],C[N];
    struct BIT
    {
        ll C[N];
        void clear(){for(int i=1;i<=n;++i)C[i]=0;}
        void Add(int x,int y)
        {
            while(x<=n)C[x]+=y,x+=x&-x;
        }
        ll Sum(int x)
        {
            ll res=0;
            while(x)res+=C[x],x-=x&-x;
            return res;
        }
    }sum,dec;
    void work(int x,int y)
    {
        int last=D[x];
        B[x]+=y;
        dec.Add(x,y);
        D[x]=max(B[x],0);
        sum.Add(x,D[x]-last);
    }
    void solve()
    {
        cin>>n>>m;
        sum.clear();
        dec.clear();
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)
        {
            B[i]=A[i]-A[i-1],D[i]=max(B[i],0);
            dec.Add(i,B[i]);
            sum.Add(i,D[i]);
        }
        for(int i=1;i<=m;++i)
        {
            int op,l,r,x;
            cin>>op>>l>>r;
            if(op==2)
                cout<<dec.Sum(l)+sum.Sum(r)-sum.Sum(l)<<'\n';
            else
            {
                cin>>x;
                work(l,x);
                work(r+1,-x);
            }

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
