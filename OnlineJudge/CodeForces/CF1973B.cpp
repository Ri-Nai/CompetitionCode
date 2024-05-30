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
        int n = rd();
        vector<int> A;
        for (int i = 0; i < n; ++i)
            A.push_back(rd());
        int l = 1, r = n, ans = n;
        while (l <= r)
        {
            int mid = l + r >> 1;
            auto check = [&](int k)
            {
                vector<int> cnt(30);
                auto Add = [&] (int x, int p)
                {
                    int res = 0;
                    for (int i = 0; i <= 20; ++i)
                        if (1 << i & x) cnt[i] += p;
                    for (int i = 0; i <= 20; ++i)
                        if (cnt[i]) res |= 1 << i;
                    return res;
                };
                int last = 0;
                for (int i = 0; i < n; ++i)
                {
                    int now = Add(A[i], 1);
                    if (i >= k)
                    {
                        now = Add(A[i - k], -1);
                        if (now != last)
                            return 0;
                    }
                    last = now;
                }
                return 1;
            };
            if (check(mid))
                r = mid - 1, ans = mid;
            else l = mid + 1;
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
