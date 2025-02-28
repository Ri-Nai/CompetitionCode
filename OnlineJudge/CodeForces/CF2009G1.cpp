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
        int n = rd(), k = rd(), q = rd();
        vector<int> A(n + 1), ans(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = rd() + n - i;
        vector<int> cnt(2 * n + 1);
        // priority_queue<int> Q;
        multiset<int> S;
        for (auto x : cnt)
            S.insert(x);
        for (int i = 1; i <= n + 1; ++i)
        {
            if (i > k)
            {
                ans[i - k] = k - *S.rbegin();
                S.erase(S.find(cnt[A[i - k]]--));
                S.insert(cnt[A[i - k]]);
            }
            if (i != n + 1)
            {
                S.erase(S.find(cnt[A[i]]++));
                S.insert(cnt[A[i]]);
            }
        }
        struct ST_TABLE
        {
            int n;
            vector<vector<int>> MN, MX;
            vector<int> lg;
            ST_TABLE() {}
            ST_TABLE(int _, const vector<int> &A)
            {
                n = _;
                lg.resize(n + 1);
                for (int i = 2; i <= n; ++i)
                    lg[i] = lg[i >> 1] + 1;
                MN.assign(n + 1, vector<int>(lg[n] + 1));
                MX.assign(n + 1, vector<int>(lg[n] + 1));
                for (int i = 1; i <= n; ++i)
                    MX[i][0] = MN[i][0] = A[i];
                for (int j = 1; j <= lg[n]; ++j)
                    for (int i = 1; i <= n; ++i)
                    {
                        if (i + (1 << j) - 1 > n)
                            continue;
                        MN[i][j] = min(MN[i][j - 1], MN[i + (1 << j - 1)][j - 1]);
                        MX[i][j] = max(MX[i][j - 1], MX[i + (1 << j - 1)][j - 1]);
                    }
            }
            int query(int l, int r, int p)
            {
                if (r < l)
                    return -1;
                int t = lg[r - l + 1];
                if (p)
                    return max(MX[l][t], MX[r - (1 << t) + 1][t]);
                else
                    return min(MN[l][t], MN[r - (1 << t) + 1][t]);
            }
        } Tr(n, ans);
        // for (int i = 1; i <= n; ++i)
        //     cout << ans[i] << " \n"[i == n];
        while (q--)
        {
            int l = rd(), r = rd();
            cout << Tr.query(l, r - k + 1, 1) << '\n';
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
