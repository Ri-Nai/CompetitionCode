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
        SA_Array(string T) : n(T.size()), SA(n + 1), rk(n + 1), height(n + 1)

        {
            S = T;
            S.push_back(0);
            for (int i = n; i >= 1; --i)
                S[i] = S[i - 1];
            S[0] = 0;
            init_SA();
            init_height();
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
        void show()
        {
            for (int i = 1; i <= n; ++i)
                cout << i << " " + S.substr(SA[i], S.size() - SA[i]) << ' ' << height[i] << "\n";
        }
    };
    void solve()
    {
        string a, b;
        cin >> a >> b;
        string s = a.substr(1, a.size() - 1) + a + "-" + b;
        SA_Array S(s);
        int n = a.size(), m = b.size();
        int now = 0;
        int ans = 0;
        S.show();
        vector<int> L(n + n + m + 1), R(n + n + m + 1);
        for (int i = 2; i <= n + n + m; ++i)
        {
            if (S.SA[i - 1] < n + n)
                now = S.height[i];
            else
                now = min(now, S.height[i]);
            L[i] = now;
        }
        now = 0;
        for (int i = n + n + m; i >= 2; --i)
        {
            R[i] = now;
            if (S.SA[i] < n + n)
                now = S.height[i];
            else
                now = min(now, S.height[i]);
        }
        for (int i = 2; i <= n + n + m; ++i)
        {
            if (S.SA[i] > n + n)
                if (max(L[i], R[i]) >= n)
                    ++ans;
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
/*
aaba

aaba
a
aba
ba
*/
