#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const db pi=asin(1)*2;
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
    void check(db a,db b,db c,db &agl1,db &agl2)
    {
        //x^2/a^2+y^2/b^2=1与x+y=c相交
        db x1,x2;
        solve(1/a/a+1/b/b,-2*c/b/b,c*c/b/b-1,x1,x2);
        if(x1==x2 and x1==-1)return agl1=pi/2,agl2=-1,void();
        db y1=c-x1,y2=c-x2;
        if(x1<0)agl1=-1;
        else agl1=asin(x1/a);
        if(y2<0)agl2=-1;
        else agl2=asin(x2/a);
    }
    bool pd(db l1,db r1,db l2,db r2)
    {
        if(l1==-1 or r1==-1 or l2==-1 or r2==-2)
            return 0;
        if(r1<l2)return 0;
        if(r2<l1)return 0;
        return 1;
    }
    void solve()
    {
        db a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
        if(d>e)swap(d,e);
        if(a>d and b>e)End("NO");
        if(a<=d and b<=e)End("YES");
        db a1,a2,a3,a4;
        check(a,b,d,a1,a2);
        check(b,a,e,a3,a4);
        // cout<<a1<<' '<<a2<<' '<<a3<<' '<<a4<<'\n';
        if(pd(0,a1,0,a3))End("YES");
        if(pd(0,a1,a4,pi/2))End("YES");
        if(pd(a2,pi/2,0,a3))End("YES");
        if(pd(a2,pi/2,a4,pi/2))End("YES");
        End("NO");
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
