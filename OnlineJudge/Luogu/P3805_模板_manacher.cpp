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
            ans = max(ans, len[i] - 1);
        }
        cout << ans << '\n';

    }
}
bool Nai;
int main()
{
    // cout << (&Nai - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
