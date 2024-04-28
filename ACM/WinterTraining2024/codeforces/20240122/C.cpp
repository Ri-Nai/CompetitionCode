#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,k;
    void solve()
    {
        cin>>n>>k;
        int l=0,r=n,res=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            ll now=1ll*mid*(mid+1)/2+k;
            //下一轮的律动+伤害就似了
            //所以减一轮
            //
            if(now<n)l=mid+1,res=mid;
            else r=mid-1;
        }
        res=max(res-1,0);
        ll now=1ll*res*(res+1)/2;
        n-=now;
        // cout<<n<<' '<<res<<'\n';
        int x=n,y=n;
        while(1)
        {
            ++res;
            x-=res;
            if(x<=0)End("freesin");
            if(y-res-k<=0)End("pllj");
            y-=res;
            x-=k;
            y-=k;
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
