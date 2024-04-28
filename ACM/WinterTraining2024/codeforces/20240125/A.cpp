#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1005;
    int n,C;
    int A[N],cnt[N];
    void solve()
    {
        cin>>n>>C;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        int ans=0;
        sort(A+1,A+n+1);
        for(int i=1;i<=n;++i)
        {
            int limit=max(0,A[i]-C);
            int t=0;
            for(int j=limit;j<=A[i];++j)
                t+=cnt[j];
            // cout<<t<<'\n';
            if(t>=2)
            {
                int now=2;
                for(int j=limit;j<=A[i];++j)
                    while(now and cnt[j])--now,--cnt[j];
                ++ans;
            }
            else ++cnt[A[i]];
        }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
