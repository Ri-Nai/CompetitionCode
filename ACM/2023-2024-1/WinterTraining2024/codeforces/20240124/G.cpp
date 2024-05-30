#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int x;
    ll L,R;
    const int N=1e4+5;
    int P[N];
    vector<int>Pr;
    void pre()
    {
        for(int i=2;i<N;++i)
        {
            if(!P[i])
            {
                Pr.push_back(i);
                for(int j=i+i;j<N;j+=i)
                    P[i]=1;
            }
        }
    }
    void solve()
    {
        cin>>x>>L>>R;
        int xtm=x;
        ll now=x;
        for(int y:Pr)
        {
            int cnt=0;
            while(x%y==0)
            {
                ++cnt;
                x/=y;
            }
            if(cnt&1)now*=y;
            if(x==1)break;
        }
        if(x>=N)now*=x;
        int l=1,r=1e8,res=1e8;
        while(l<=r)
        {
            int mid=l+r>>1;
            ll p=1ll*mid*mid;
            if(p>=(L-1)/now+1)r=mid-1,res=mid;
            else l=mid+1;
        }
        int lp=res;
        l=1,r=1e8,res=-1;
        while(l<=r)
        {
            int mid=l+r>>1;
            ll p=1ll*mid*mid;
            if(p<=R/now)l=mid+1,res=mid;
            else r=mid-1;
        }
        int rp=res;
        if(lp>rp)End(-1);
        else End(1ll*now/xtm*lp*lp);
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    T::pre();
    int t;cin>>t;while(t--)
    T::solve();

}
