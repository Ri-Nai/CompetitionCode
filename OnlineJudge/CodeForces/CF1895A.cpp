#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        int x,y,k;
        cin>>x>>y>>k;
        // int l=x-k,r=x+k;
        // int ans=y+abs(y-x);
        // if(y>=l and y<=r)End(min(ans,abs(x)+k));
        // End(min(ans,x+abs(y-x)*2-k));
        if(y<=x)End(x);
        if(x+k>=y)End(y);
        End(y+(y-x-k));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
