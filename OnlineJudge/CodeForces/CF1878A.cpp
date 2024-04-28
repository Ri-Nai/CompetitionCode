#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=105;
    int n,k,A[M],cnt[M];
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)
            cin>>A[i],cnt[i]=cnt[i-1]+(A[i]==k);
        for(int i=1;i<=n;++i)
        {
            if(A[i]==k)End("YES");
        }
        End("NO");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
