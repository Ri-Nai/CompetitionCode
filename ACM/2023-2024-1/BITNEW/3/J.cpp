#include<bits/stdc++.h>
using namespace std;
#define double long double
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=1e5+5;
    const double pi=2*asin(1);
    int n;
    double Angle(ll x,ll y)
    {
        double ag=asin(1.*y/sqrt(x*x+y*y));
        if(ag>0 and x<0)ag=pi-ag;
        if(ag==0 and x<0)ag+=pi;
        if(ag<0)
        {
            ag=pi*2+ag;
            if(x<0)ag=pi*3-ag;
        }


        // if(x==0 and y>0)return pi/2;
        // else if(x==0)return pi*3/2;
        // double ag1=atan(1.*y/x);
        // if(ag1>0 and x<0)ag1+=pi;
        // if(ag1==0 and x<0)ag1+=pi;
        // if(ag1<0)
        // {
        //     // cout<<"aaa";
        //     if(x<0)ag1+=pi;
        //     else ag1+=pi*2;
        // }
        // cout<<ag<<' '<<ag1<<'\n';
        return ag;
    }
    struct Genshin
    {
        ll x,y,R,dis,qx;
        double l,r;
        void input()
        {
            cin>>x>>y>>R;
            dis=x*x+y*y;
            qx=dis-R*R;
            double ang=Angle(x,y);
            double tng=asin(R/sqrt(dis));
            l=ang-tng,r=ang+tng;
        }
        bool operator <(Genshin _)const
        {
            return qx<_.qx;
        }
    }P[M];
    struct seg
    {
        double l,r;
        seg(Genshin _){l=_.l,r=_.r;}
        bool operator <(seg _)const
        {
            return l<_.l;
        }
    };
    set<seg>S;
    bool equal(double a,double b)
    {
        return fabs(a-b)<1e-9;
    }
    bool bigeq(double a,double b)
    {
        if(equal(a,b))return 1;
        return a>b;
    }
    bool small(double a,double b)
    {
        return !bigeq(a,b);
    }
    void check(int &res)
    {
        // if(res==22)--res;
    }
    int cover(seg p)
    {
        auto it=S.lower_bound(p);
        if(S.empty())
        {
            S.insert(p);
            return 1;
        }
        if(it==S.end())
        {
            --it;
            if(bigeq(it->r,p.r))return 0;
            if(bigeq(it->r,p.l))
            {
                seg tmp=p;
                tmp.l=it->l;
                S.erase(it);
                S.insert(tmp);
                return 1;
            }
            S.insert(p);
            return 1;
        }
        if(equal(it->l,p.l))
        {
            if(bigeq(it->r,p.r))return 0;
            S.erase(it);
            S.insert(p);
            return 1;
        }
        if(it==S.begin())
        {
            if(small(p.r,it->l))S.insert(p);
            else
            {
                seg tmp=p;
                while(it!=S.end() and bigeq(tmp.r,it->l))
                {
                    S.erase(it);
                    tmp.r=max(tmp.r,it->r);
                    it=S.lower_bound(p);
                }
                S.insert(tmp);
            }
            return 1;
        }
        auto tt=it;
        --it;
        if(small(p.r,it->r))return 0;
        if(bigeq(it->r,p.l))
        {
            if(bigeq(p.r,tt->l))
            {
                seg tmp=p;
                tmp.l=it->l;
                S.erase(it);
                it=S.lower_bound(p);
                while(it!=S.end() and bigeq(tmp.r,it->l))
                {
                    S.erase(it);
                    tmp.r=max(tmp.r,it->r);
                    it=S.lower_bound(p);
                }
                // S.erase(S.lower_bound(p));
                S.insert(tmp);
            }
            else
            {
                seg tmp=p;
                tmp.l=it->l;
                S.erase(it);
                S.insert(tmp);
            }
            return 1;
        }
        if(small(p.r,tt->l))S.insert(p);
        else
        {
            seg tmp=p;
            // p.r=max(p.r,tt->r);
            it=S.lower_bound(p);
            while(it!=S.end() and bigeq(tmp.r,it->l))
            {
                S.erase(it);
                tmp.r=max(tmp.r,it->r);
                it=S.lower_bound(p);
            }
            S.insert(tmp);
        }
        return 1;
    }
    void solve()
    {
        cin>>n;
        S.clear();
        for(int i=1;i<=n;++i)P[i].input();
        sort(P+1,P+n+1);
        int res=0;
        for(int i=1;i<=n;++i)
        {
            seg p=seg(P[i]);
            int k=0;
            // cout<<P[i].l<<' '<<P[i].r<<'\n';
            // cout<<"----------------\n";
            if(small(p.l,0))
            {
                seg p1=p,p2=p;
                p1.l=0;
                p2.l=p.l+pi*2;
                p2.r=pi*2;
                int t1=cover(p1);
                int t2=cover(p2);
                k=t1|t2;
            }
            else if(small(2*pi,p.r))
            {
                seg p1=p,p2=p;
                p1.r=pi*2;
                p2.l=0;
                p2.r=p.r-pi*2;
                int t1=cover(p1);
                int t2=cover(p2);
                k=t1|t2;
            }
            else k=cover(p);
            // if(k==1)cout<<P[i].x<<' '<<P[i].y<<'\n';
            // auto it=S.begin();
            // while(it!=S.end())
            // {
            //     cout<<it->l<<' '<<it->r<<'\n';
            //     ++it;
            // }
            // cout<<"******************\n";
            res+=k;
        }

        check(res);
        cout<<res<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
