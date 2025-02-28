#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
int rd()
{
    int res = 0, f = 1;
    char c;
    do
        (c = getchar()) == '-' && (f = -1);
    while (!isdigit(c));
    while (isdigit(c))
        res = (c ^ 48) + (res << 1) + (res << 3), c = getchar();
    return res * f;
}
bool Ri;
const int M = (1 << 20) + 5;
const int P1 = 19260817, mod1 = 1e9 + 7, P2 = 233, mod2 = 998244353;
int hsh1[M + M], hsh2[M + M], pw1[M], pw2[M], hshb1[M], hshb2[M];
int main()
{
    ios::sync_with_stdio(0);
    // freopen("Data.in", "r", stdin);
    int t;
    cin >> t;
    pw1[0] = 1, pw2[0] = 1;
    for (int i = 1; i < M; ++i)
        pw1[i] = 1ll * P1 * pw1[i - 1] % mod1;
    for (int i = 1; i < M; ++i)
        pw2[i] = 1ll * P2 * pw2[i - 1] % mod2;
    auto solve = [&]()
    {
        string a, b;
        cin >> a >> b;
        string t = a + a;
        int n = a.size(), m = b.size();
        for (int i = 1; i < n + n; ++i)
        {
            hsh1[i] = (1ll * hsh1[i - 1] * P1 % mod1 + t[i]) % mod1;
            hsh2[i] = (1ll * hsh2[i - 1] * P2 % mod2 + t[i]) % mod2;
        }
        map<pair<int, int>, int> has;
        auto get_hash = [&](int l, int r, int *hash1, int *hash2)
        {
            return make_pair((hash1[r] - 1ll * hash1[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1,
                             (hash2[r] - 1ll * hash2[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2);
        };
        for (int i = 1; i <= n; ++i)
            has[get_hash(i, i + n - 1, hsh1, hsh2)] = 1;
        for (int i = 1; i <= m; ++i)
        {
            hshb1[i] = (1ll * hshb1[i - 1] * P1 % mod1 + b[i - 1]) % mod1;
            hshb2[i] = (1ll * hshb2[i - 1] * P2 % mod2 + b[i - 1]) % mod2;
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (i + n - 1 <= m)
            {
                int t = has[get_hash(i, i + n - 1, hshb1, hshb2)];
                ans += t;
            }
        }
        cout << ans << '\n';
    };
    while (t--)
        solve();
}
/*
9 17 25 21 5 13 1 11 24 10 22 6 14 18 2 23 7 15 19 3 8 16 20 4 12
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
1 -JDRCJMRAJMRCJMGC 0
2 AJMRCJMGC 0
3 C 0
4 CJMGC 1
5 CJMR-JDRCJMRAJMRCJMGC 3
6 CJMRAJMRCJMGC 4
7 CJMRCJMR-JDRCJMRAJMRCJMGC 4
8 DRCJMRAJMRCJMGC 0
9 GC 0
10 JDRCJMRAJMRCJMGC 0
11 JMGC 1
12 JMR-JDRCJMRAJMRCJMGC 2
13 JMRAJMRCJMGC 3
14 JMRCJMGC 3
15 JMRCJMR-JDRCJMRAJMRCJMGC 6
16 MGC 0
17 MR-JDRCJMRAJMRCJMGC 1
18 MRAJMRCJMGC 2
19 MRCJMGC 2
20 MRCJMR-JDRCJMRAJMRCJMGC 5
21 R-JDRCJMRAJMRCJMGC 0
22 RAJMRCJMGC 1
23 RCJMGC 1
24 RCJMR-JDRCJMRAJMRCJMGC 4
25 RCJMRAJMRCJMGC 5
0 0 0 1 3 4 4 0 0 0 1 2 3 3 6 0 1 2 2 5 0 1 1 4 5
*/
