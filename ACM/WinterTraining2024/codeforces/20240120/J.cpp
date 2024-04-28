#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    void solve()
    {
        int mn=0;
        int x;
        cin>>n;
        cin>>x;
        --n;
        mn=3*x;
        while(n--)
        {
            cin>>x;
            mn=max(mn,x+1);
        }
        if(mn&1)mn+=1;
        cout<<mn<<'\n';
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
