#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,A[N];
    void solve()
    {
        cin>>n;
        int p=1;
        for(int i=1;i<=n;++i)
            cin>>A[i],A[i]<A[p]&&(p=i);
        for(int i=p+1;i<=n;++i)
            if(A[i]<A[i-1])End("-1");
        End(p-1);

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
