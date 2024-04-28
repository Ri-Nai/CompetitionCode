#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Nai;
namespace T
{
    const int mod=1e9+7;
    const int N=2e5+5;
    #define Add(x,y) (x=(x+(y)%mod)%mod)
    int n,m;
    int A[N];
    struct Que
    {
        int l,r,id;
        void input(int p)
        {
            cin>>l>>r;
            id=p;
        }
    }T;
    vector<Que>E;
    ll ans[N];
    ll l[N][20],r[N][20];
    void Work(vector<Que> v,int L,int R)
    {
        if(L==R)
        {
            for(auto t:v)Add(ans[t.id],1+(A[L]==0));
            return ;
        }
        // cout<<"AAA\n";
        // cout<<L<<' '<<R<<'\n';
        int mid=L+R>>1;
        l[mid+1][0]=r[mid][0]=1;
        for(int i=1;i<m;++i)l[mid+1][i]=r[mid][i]=0;
        for(int i=mid;i>=L;--i)
            for(int j=0;j<m;++j)
                l[i][j]=0,Add(l[i][j],l[i+1][j]+l[i+1][(j+m-A[i])%m]);
        for(int i=mid+1;i<=R;++i)
            for(int j=0;j<m;++j)
                r[i][j]=0,Add(r[i][j],r[i-1][j]+r[i-1][(j+m-A[i])%m]);
        vector<Que>vl,vr;
        for(auto t:v)
        {
            int pl=t.l,pr=t.r;
            if(pr<=mid)vl.push_back(t);
            else if(pl>mid)vr.push_back(t);
            else
                for(int j=0;j<m;++j)
                {
                    // cout<<t.id<<'\n';
                    Add(ans[t.id],1ll*l[pl][j]*r[pr][(m-j)%m]);
                }
        }
        Work(vl,L,mid);
        Work(vr,mid+1,R);
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>A[i],A[i]%=m;
        int q;cin>>q;
        for(int i=1;i<=q;++i)T.input(i),E.push_back(T);
        Work(E,1,n);
        for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
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
