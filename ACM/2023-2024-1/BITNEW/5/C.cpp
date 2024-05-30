#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    void solve()
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int x,y,r;
        cin>>x>>y>>r;
        if(x-r<x1 or x+r>x2 or y-r<y1 or y+r>y2)End("No");
        End("Yes");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
