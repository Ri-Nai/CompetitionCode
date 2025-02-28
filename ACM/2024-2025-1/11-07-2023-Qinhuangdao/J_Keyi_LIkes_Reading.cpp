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
        int n, W;
        scanf("%d%d", &n, &W);
        vector<int> cnt(14);
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        sort(cnt.begin(), cnt.end());
        reverse(cnt.begin(), cnt.end());
        while (cnt.back() == 0)
            cnt.pop_back();
        n = cnt.size();
        int S = 1 << n;
        vector<int> total(S);
        for (int i = 0; i < S; ++i)
            for (int j = 0; j < n; ++j)
                if (1 << j & i)
                    total[i] += cnt[j];
        vector<int> dp(S, 11231);
        dp[0] = 0;
        for (int i = 0; i < S; ++i)
            for (int j = i; j; j = (j - 1) & i)
                if (total[j] <= W)
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
        cout << dp[S - 1] << endl;
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
