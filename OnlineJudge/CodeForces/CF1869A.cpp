#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=105;
    int n,A[M];
    void solve()
    {
        cin>>n;
        for(int i=1,x;i<=n;++i)
            cin>>x;
        cout<<5<<"\n";
        cout<<1<<' '<<n<<"\n";
        cout<<1<<' '<<n<<"\n";
        cout<<2<<' '<<n<<"\n";
        cout<<1<<' '<<2<<"\n";
        cout<<1<<' '<<2<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)T::solve();

}
