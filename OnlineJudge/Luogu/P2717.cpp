#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout << X << '\n', void()
bool Nai;
namespace T
{
    const int N = 1e5 + 5;
    struct BIT
    {
        int C[N], n;
        void init(int _)
        {
            n = _;
            for (int i = 0; i <= n; ++i)
                C[i] = 0;
        }
        void Add(int x, int y)
        {
            while (x <= n)
                C[x] += y, x += x & -x;
        }
        int Sum(int x)
        {
            int res = 0;
            while (x)
                res += C[x], x -= x & -x;
            return res;
        }
    } T;
    int n, k, A[N], tmp[N];
    void solve()
    {
        cin >> n >> k;
        //        cout<<n<<' '<<k<<'\n';
        for (int i = 1; i <= n; ++i)
            cin >> A[i], A[i] += A[i - 1] - k, tmp[i] = A[i];
        sort(tmp, tmp + n + 1);
        int l = unique(tmp, tmp + n + 1) - tmp;
        for (int i = 1; i <= n; ++i)
            A[i] = lower_bound(tmp, tmp + l, A[i]) - tmp + 1;
        // for(int i=0;i<=n;++i)cout<<A[i]<<'\n';
        //		cout<<l<<'\n';
        T.init(l + 5);
        ll ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            ans += T.Sum(A[i]);
            //			cout<<T.Sum(A[i]);
            T.Add(A[i], 1);
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();
}
