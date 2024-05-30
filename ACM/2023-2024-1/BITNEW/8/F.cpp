#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=15;
    db X;
    int n;
    db dis[N],R[N],G[N];
    void solve(db a,db b,db c,db &x1,db &x2)
    {
        db dt=b*b-4*a*c;
        if(dt<0)x1=x2=-1;
        else
        {
            x1=(-b-sqrt(dt))/2/a;
            x2=(-b+sqrt(dt))/2/a;
        }
    }
    db Time(db x,db v)
    {
        db t1,t2;
        solve();
    }
    void dfs(int p,db t,db v)
    {
        if(p==n)
        {

        }
    }
    void solve()
    {
        while(~scanf("%lf%d",&X,&n))
        {
            for(int i=1;i<=n;++i)
                scanf("%lf%lf%lf",&dis[i],&R[i],&G[i]);
            dis[0]=0;
            dfs(0,0,0);
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    // while(~scanf("%"
    T::solve();

}
