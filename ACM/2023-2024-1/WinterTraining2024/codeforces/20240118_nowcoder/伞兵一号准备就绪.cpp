#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e3+5;
    int n,X[N],Y[N],tot;
    ll C[N];
    int gcd(int a,int b)
    {
        if(b<0)return gcd(a,-b);
        return b?gcd(b,a%b):a;
    }
    struct Vector
    {
        int x,y;
        bool operator <(const Vector&_)const
        {
            if(x==_.x)return y<_.y;
            return x<_.x;
        }
    };
    struct point
    {
        ll x,y,sum;
        bool operator<(const point &_)const
        {
            if(x==_.x)
            {
                if(y==_.y)return sum<_.sum;
                return y<_.y;
            }
            return x<_.x;
        }
    };
    set<point>E[N*N];
    map<Vector,int>mp;
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>X[i]>>Y[i]>>C[i];
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                int a=X[j]-X[i];
                int b=Y[j]-Y[i];
                if(a<0)a=-a,b=-b;
                if(a==0 and b<0)b=-b;
                int g=gcd(a,b);
                a/=g,b/=g;
                ll mx=(X[j]+X[i]);
                ll my=(Y[j]+Y[i]);
                // x0(a,b)+y0(-b,a)=(mx,my);
                ll tx=a*mx+b*my;
                ll ty=a*my-b*mx;
                Vector v=(Vector){a,b};
                if(!mp[v])mp[v]=++tot;
                int id=mp[v];
                point p=(point){tx,ty,-1};
                point q=(point){tx,ty,C[i]+C[j]};
                auto it=E[id].lower_bound(p);
                if(it!=E[id].end() and it->x==tx and it->y==ty)
                {
                    if(it->sum<C[i]+C[j])
                    {
                        E[id].erase(it);
                        E[id].insert(q);
                    }
                }
                else E[id].insert(q);
            }
        }
        ll ans=-1;
        for(int i=1;i<=tot;++i)
        {
            // cout<<i<<'\n';
            for(auto j=E[i].begin();j!=E[i].end();++j)
            {
                auto k=j;
                ll mx1=-1e18,mx2=-1e18;
                while(k!=E[i].end() and j->x==k->x)
                {
                    // cout<<j->sum<<' '<<k->sum<<'\n';
                    if(k->sum>mx1)mx2=mx1,mx1=k->sum;
                    else if(k->sum>mx2)mx2=k->sum;
                    ++k;
                }
                // cout<<mx1<<"*"<<mx2<<'\n';
                ans=max(ans,mx1+mx2);
                j=k;
                --j;
            }
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
signed main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
