#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{

    void solve()
    {
        int n;
        cin>>n;
        int x1=0,x2=0;
        for(int i=1;i<=n;++i)
        {
            int x,lst;
            cin>>x;
            if(i!=1)x1+=x==lst;
            lst=x;
        }
        for(int i=1;i<=n;++i)
        {
            int x,lst;
            cin>>x;
            if(i!=1)x2+=x==lst;
            lst=x;
        }
        cout<<(x1>x2?"Alice":"Bob")<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
