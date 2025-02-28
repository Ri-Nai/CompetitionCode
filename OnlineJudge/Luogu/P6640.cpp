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
    struct SA_Array
    {
        int n;
        string S;
        vector<int> SA, height, rk, lg2;
        vector<vector<int>> ST;
        SA_Array(string T) : n(T.size()), SA(n + 1), rk(n + 1), height(n + 1),
                             ST(n + 1), lg2(n + 1)

        {
            S = T;
            S.push_back(0);
            for (int i = n; i >= 1; --i)
                S[i] = S[i - 1];
            S[0] = 0;
            init_SA();
            init_height();
            init_ST();
        }
        void init_SA()
        {
            int m = 128;
            vector<int> cnt(m + 1), X(n + 1), Y(n + 1);
            for (int i = 1; i <= n; ++i)
                ++cnt[X[i] = S[i]];
            for (int i = 1; i < m; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; --i)
                SA[cnt[X[i]]--] = i;
            for (int l = 1; l < n; l <<= 1)
            {
                int tot = 0;
                for (int i = n - l + 1; i <= n; ++i)
                    Y[++tot] = i;
                for (int i = 1; i <= n; ++i)
                    if (SA[i] > l)
                        Y[++tot] = SA[i] - l;
                cnt.assign(m + 1, 0);
                for (int i = 1; i <= n; ++i)
                    ++cnt[X[i]];
                for (int i = 1; i <= m; ++i)
                    cnt[i] += cnt[i - 1];
                for (int i = n; i >= 1; --i)
                    SA[cnt[X[Y[i]]]--] = Y[i];
                swap(X, Y);
                m = 0;
                for (int i = 1; i <= n; ++i)
                    X[SA[i]] = (m += !(Y[SA[i]] == Y[SA[i - 1]] && Y[SA[i] + l] == Y[SA[i - 1] + l]));
                if (m == n)
                    break;
            }
            rk.assign(X.begin(), X.begin() + n + 1);
        }
        void init_height()
        {
            for (int i = 1, k = 0; i <= n; ++i)
            {
                if (rk[i] == 1)
                    continue;
                if (k)
                    --k;
                int j = SA[rk[i] - 1];
                while (j + k <= n && i + k <= n && S[i + k] == S[j + k])
                    ++k;
                height[rk[i]] = k;
            }
        }
        void init_ST()
        {
            lg2[1] = 0;
            for (int i = 2; i <= n; ++i)
                lg2[i] = lg2[i >> 1] + 1;
            for (int i = 1; i <= n; ++i)
                ST[i].resize(lg2[n] + 1), ST[i][0] = height[i];
            for (int j = 0; j < lg2[n]; ++j)
                for (int i = 1; i + (1 << j) <= n; ++i)
                    ST[i][j + 1] = min(ST[i][j], ST[i + (1 << j)][j]);
        }
        int Query_LCP(int l, int r)
        {
            if (l == r)
                return n - l + 1;
            l = rk[l], r = rk[r];
            if (l > r)
                swap(l, r);
            ++l;
            int p = lg2[r - l + 1];
            return min(ST[l][p], ST[r - (1 << p) + 1][p]);
        }
        int Query_Range(int l1, int r1, int l2, int r2)
        {
            int len = min(r1 - l1, r2 - l2);
            int ans = Query_LCP(l1, l2);
            return min(len, ans);
        }
    };

    void solve()
    {
        string s, t;
        cin >> s >> t;
        string T = s + '*' + t;
        SA_Array S(T);
        int n = s.size(), m = t.size();
        vector<int> ans(n + 1);
        int now = 0;
        for (int i = 2; i <= n + m + 1; ++i)
        {
            if (S.SA[i - 1] > n + 1)
                now = S.height[i];
            else now = min(now, S.height[i]);
            if (S.SA[i] <= n)
                ans[S.SA[i]] = now;
        }
        now = 0;
        for (int i = 1; i <= n + m + 1; ++i)
        {
            if (S.SA[i] <= n)
                ans[S.SA[i]] = max(ans[S.SA[i]], now);
            if (S.SA[i] > n + 1)
                now = S.height[i];
            else now = min(now, S.height[i]);
        }
        // for (int i = 1; i <= n; ++i)
        //     cout << ans[i] << '\n';
        vector<int> lg2(n + 1);
        for (int i = 2; i <= n; ++i)
            lg2[i] = lg2[i >> 1] + 1;
        vector<vector<int>> ST(n + 1, vector<int>(lg2[n] + 1));
        for (int i = 1; i <= n; ++i)
            ST[i][0] = ans[i];
        for (int i = 1; i <= lg2[n]; ++i)
        {
            int l = 1 << i;
            for (int j = 1; j <= n - l + 1; ++j)
                ST[j][i] = max(ST[j + (l >> 1)][i - 1], ST[j][i - 1]);
        }
        auto query = [&](int l, int r)
        {
            auto query_ST = [&](int l, int r)
            {
                int p = lg2[r - l + 1];
                if (r < l)
                    return 0;
                // cout << l << ' ' << r << '\n';
                return max(ST[l][p], ST[r - (1 << p) + 1][p]);
            };
            auto find_pos = [&](int l, int r)
            {
                int L = l, R = r, res = r + 1;
                while (L <= R)
                {
                    int mid = L + R >> 1;
                    if (ans[mid] <= mid - l + 1)
                        res = mid, R = mid - 1;
                    else
                        L = mid + 1;
                }
                return res;
            };
            int pos = find_pos(l, r);
            query_ST(pos, r);
            return max(pos - l, query_ST(pos, r));
        };
        for (int q = rd(); q--;)
        {
            int l = rd(), r = rd();
            cout << query(l, r) << '\n';
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
