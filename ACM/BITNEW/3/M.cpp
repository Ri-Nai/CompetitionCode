#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        double len;
        len=min(1.*(d-a)/2,1.*min(d-c,b-a));
        printf("%.2f\n",len);
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
