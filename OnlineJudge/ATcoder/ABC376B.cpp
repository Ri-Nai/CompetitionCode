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
        int n = rd(), Q = rd();
        vector<int> pos{1, 2};
        long long ans = 0;
        while (Q--)
        {
            int op = getchar() == 'R', nxt = rd();
            // cout << op << ' ' << nxt << endl;
            auto checkMid = [&](int l, int r, int x)
            {
                if (r < l)
                    swap(l, r);
                return x >= l && x <= r;
            };
            if (pos[op] == nxt)
                continue;
            else if (!checkMid(nxt, pos[op], pos[op ^ 1]))
                // cout << "?",
                ans += abs(pos[op] - nxt);
            else
                ans += n - abs(pos[op] - nxt);
            // cout << ans << endl;
            pos[op] = nxt;
        }
        cout << ans << endl;
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
