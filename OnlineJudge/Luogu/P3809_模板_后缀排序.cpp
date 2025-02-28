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
        string S;
        cin >> S;
        int n = S.size(), m = 128;
        S.push_back(0);
        for (int i = n; i >= 1; --i)
            S[i] = S[i - 1];
        S[0] = 0;
        vector<int> SA(n + 1), cnt(m), X(n * 2 + 1), Y(n * 2 + 1);
        for (int i = 1; i <= n; ++i) ++cnt[X[i] = S[i]];
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; --i) SA[cnt[X[i]]--] = i;
        for (int l = 1; l < n; l <<= 1)
        {
            int tot = 0;
            for (int i = n - l + 1; i <= n; ++i)
                Y[++tot] = i;
            for (int i = 1; i <= n; ++i)
                if (SA[i] > l)
                    Y[++tot] = SA[i] - l;
            // cout << tot << '\n';
            cnt.assign(m, 0);
            for (int i = 1; i <= n; ++i) ++cnt[X[i]];
            for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; --i) SA[cnt[X[Y[i]]]--] = Y[i];
            swap(X, Y);
            m = 0;
            for (int i = 1; i <= n; ++i)
                X[SA[i]] = (m += !(Y[SA[i]] == Y[SA[i - 1]] && Y[SA[i] + l] == Y[SA[i - 1] + l]));
            if (m++ == n)
                break;
        }
        for (int i = 1; i <= n; ++i)
            cout << SA[i] << " \n"[i == n];
        for (int i = 1; i <= n; ++i)
            X[SA[i]] = i;
        for (int i = 1; i <= n; ++i)
            cout << SA[X[i]] << " \n"[i == n];
        vector<int> height(n + 1);
        for (int i = 1, k = 0; i <= n; ++i)
        {
            if (X[i] == 1)
                continue;
            if (k) --k;
            int j = SA[X[i] - 1];
            while (j + k <= n && i + k <= n && S[i + k] == S[j + k]) ++k;
            height[X[i]] = k;
        }
        for (int i = 1; i <= n; ++i)
            cout << i << " " + S.substr(SA[i], S.size() - SA[i]) << ' ' << height[i] << "\n";
        for (int i = 1; i <= n; ++i)
            cout << height[i] << " \n"[i == n];
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
