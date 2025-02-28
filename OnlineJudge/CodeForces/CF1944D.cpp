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
namespace T
{
    void solve()
    {
        int n, Q;
        cin >> n >> Q;
        string S;
        cin >> S;
        S = '#' + S;
        auto manacher = [&]()
        {
            vector<int> T{0};
            for (auto c : S)
                T.push_back(c), T.push_back(0);
            int n = T.size();
            vector<int> len(n);
            int ans = 1;
            for (int i = 0, mid = 0; i < n; ++i)
            {
                int now = 2 * mid - i, limit = mid + len[mid] - i;
                if (now >= 0 && limit > 0)
                    len[i] = min(len[now], limit);
                while (i - len[i] >= 0 && i + len[i] < n && T[i - len[i]] == T[i + len[i]])
                    ++len[i];
                if (i + len[i] > mid + len[mid])
                    mid = i;
            }
            return len;
        };
        auto len = manacher();
        auto cnt = vector(n + 1, vector<int>(26));
        for (int i = 1; i <= n; ++i)
        {
            cnt[i] = cnt[i - 1];
            ++cnt[i][S[i] - 'a'];
        }
        auto checkOK1 = [&](int l, int r)
        {
            int num = 0;
            for (int i = 0; i < 26; ++i)
            {
                num += !!(cnt[r][i] - cnt[l - 1][i]);
                if (num > 1)
                    return 0;
            }
            return 1;
        };
        auto checkOKtotal = [&](int l, int r)
        {
            int L = 2 * l + 1, R = 2 * r + 1;
            int mid = L + R >> 1;
            return len[mid] >= mid - L + 1;
        };
        auto OK3 = vector(n, vector<int>(20));
        vector<int> lg(n + 1);
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i >> 1] + 1;
        for (int i = 1; i <= n - 2; ++i)
            OK3[i][0] = S[i] == S[i + 2];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i + (1 << j) <= n - 2; ++i)
                OK3[i][j] = OK3[i][j - 1] && OK3[i + (1 << j)][j - 1];
        auto checkOK3 = [&](int l, int r) -> bool
        {
            if (r - l + 1 < 3)
                return 0;
            r -= 2;
            int p = lg[r - l + 1];
            return OK3[l][p] && OK3[r - (1 << p) + 1][p];
        };
        auto query = [&]()
        {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            if (checkOK1(l, r))
                End(0);
            auto sum = [](int l, int r, int p = 1) -> ll
            {
                if (r < l)
                    return 0;
                return 1ll * (r + l) * ((r - l) / p + 1) >> 1;
            };
            if (checkOK3(l, r))
            {
                int down = 3, up = len - (len & 1 ^ 1);
                End(sum(2, len) - sum(down, up, 2));
            }
            if (checkOKtotal(l, r))
                End(sum(2, len - 1));
            End(sum(2, len));
        };
        while (Q--)
            query();
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
/*
abcba
acbcacb
*/
