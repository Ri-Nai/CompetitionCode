#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=105;
    int n,A[M],B[M];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i]>>B[i];
        for(int i=2;i<=n;++i)
        {
            if(A[i]>=A[1] and B[i]>=B[1])
                End("-1");
        }
        cout<<A[1]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}

// using i64 = long long;

// void solve() {
//     int n;
//     std::cin >> n;

//     std::vector<int> s(n), e(n);
//     bool ok = true;
//     for (int i = 0; i < n; i++) {
//         std::cin >> s[i] >> e[i];
//         if (i > 0 && s[i] >= s[0] && e[i] >= e[0]) {
//             ok = false;
//         }
//     }
//     std::cout << (ok ? s[0] : -1) << "\n";
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int t;
//     std::cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }
