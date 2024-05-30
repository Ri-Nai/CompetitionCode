#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,B[N];
    int rd()
    {
        int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
        while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
        return f?-t:t;
    }
    ll Query(int x)
    {
        ll ans=B[x];
        for(int i=x+1;i<=n;++i)
        {
            if(1ll*(i-x)*(i-x)>B[x])break;
            ans=min(1ll*(i-x)*(i-x)+B[i],ans);
        }
        for(int i=x-1;i>=1;--i)
        {
            if(1ll*(i-x)*(i-x)>B[x])break;
            ans=min(1ll*(i-x)*(i-x)+B[i],ans);
        }
        return ans;
    }
    void solve()
    {
        n=rd();
        for(int i=1;i<=n;++i)B[i]=rd();
        for(int m=rd();m--;)
        {
            int op=rd();
            if(op)
                cout<<Query(rd())<<'\n';
            else
            {
                int a=rd(),b=rd();
                B[a]=min(B[a],b);
            }
        }

    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
