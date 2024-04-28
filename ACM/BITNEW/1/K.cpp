#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        ll h,x,y;
        int n;
        cin>>h>>x>>y>>n;
        bool flag=0;
        ll hp=h;
        for(int i=1;i<=n;++i)
        {
            int now;
            cin>>now;
            if(!flag)
            {
                if(hp-now<=0)
                {
                    if(y-x<0)
                    {
                        flag=1;
                        cout<<i<<'\n';
                    }
                    else
                    {
                        hp=h;
                        y-=x;
                        x*=2;
                    }
                }
                else hp-=now;
            }
        }
        if(!flag)cout<<n+1<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
