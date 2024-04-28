#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n,d;
    const int N=1e4+5;
    const double eps=1e-6;
    bool mark[N];
    double ans[N];
    struct Genshin
    {
        double x,y,vx,vy;
        void input()
        {
            cin>>x>>y>>vx>>vy;
        }
        double dis(const double &t,const Genshin &_)
        {
            return pow((x+vx*t-_.x-_.vx*t),2)+pow((y+vy*t-_.y-_.vy*t),2);
        }
        double slope(const double &t,const Genshin &_)
        {
            return dis(t,_)-dis(t-eps,_)/eps;
        }
    }P[N];
    struct Persona
    {
        double time;
        int id;
        Persona(double _,int __){time=_,id=__;}
    };
    void Make(int x,int y)
    {
        double l=0,r=40,mid,res=-1;
        auto dis=[x,y](double t){return P[y].dis(t,P[x]);};
        auto slope=[x,y](double t){return P[y].slope(t,P[x]);};
        cout<<slope(0)<<' '<<slope(r)<<'\n';
        if(slope(l)*slope(r)>0)return;
        while(l<r-eps)
        {
            mid=(l+r)/2;
            if(slope(mid)>0)res=mid,r=mid;
            else l=mid;
        }
        if(dis(res)>d*d)return;
        // if(dis(res)<=)
        l=0,r=res;
        while(l<r-eps)
        {
            mid=(l+r)/2;
            if(dis(mid)>d*d)res=mid,r=mid;
            else l=mid;
        }
        // cout<<res<<'\n';
    }
    void solve()
    {
        cin>>n>>d;
        for(int i=0;i<=n;++i)P[i].input();
        // for(int i=1;i<=n;++i)Make(i);
        // Q.push(0);mark[0]=1;

    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
