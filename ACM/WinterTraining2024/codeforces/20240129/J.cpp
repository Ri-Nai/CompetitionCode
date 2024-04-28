#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{

    void solve()
    {
        int n;
        cin>>n;
        if(n<=5)End("-1");
        else
        {
            if(n&1)cout<<3<<' '<<n-3<<'\n';
            else cout<<2<<' '<<n-2<<"\n";
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
