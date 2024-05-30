#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,k;
    int A[N];
    void solve()
    {
        // cin>>n>>k;
        scanf("%d%d",&n,&k);
        ll S=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]),S+=A[i];
        for(int i=1;i<=n;++i)
            printf("%.8lf%c",1.*A[i]*k/S+A[i]," \n"[i==n]);
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
