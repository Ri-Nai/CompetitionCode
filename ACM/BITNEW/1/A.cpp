#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()

namespace T
{

    struct Big
    {
        ll A[55];
        int n;
        Big(){memset(A,0,sizeof A);A[n=1]=1;}
        void Mul(ll t)
        {
            ll lst=0;
            for(int i=1;i<=n;++i)
            {
                ll now=A[i];
                now*=t;
                now+=lst;
                A[i]=now%10;
                lst=now/10;
                if(i==n and lst)
                    ++n;
            }
        }

    };
    void solve()
    {
        int a;
        // cin>>a;
        // puts("aaa");
        scanf("%d",&a);
        ll t=11845019656750059;
        Big Ans;
        Ans.Mul(1ll*a*a);
        Ans.Mul(t);
        for(int i=Ans.n;i>=7;--i)
        {
            if(i==16)printf(".");
            printf("%lld",Ans.A[i]);
        }
        // cout<<1.*t/4<<'\n';
        // printf("%.2f\n",.25*t);
        puts("");
        // long double ans=4.7380078627/4*a*a;
        // printf("%.10Lf\n",ans);
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
