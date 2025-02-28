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
        int n = rd(), k = rd();
        map<int, int> has;
        for (int i = 0; i < n; ++i)
            ++has[rd()];
        vector<pair<int, int>> A;
        for (auto x : has)
            A.push_back(x);
        int ans = 0, now = 0;
        for (int i = 0, j = 0; i < A.size(); ++i)
        {
            while (j < A.size() && j - i < k && A[j].first - A[i].first == j - i)
            {
                now += A[j].second;
                ++j;
            }
            ans = max(ans, now);
            now -= A[i].second;
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
