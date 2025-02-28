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
        vector<int> A(n + 1);
        typedef unsigned long long ull;
        map<ull, int> cnt;
        map<pair<int, int>, int> pos;
        map<int, int> num;
        map<int, ull> total;
        vector<ull> Hash(n + 1);
        vector<int> numer(n + 1);
        mt19937_64 mrand(231654);
        auto RAND = [&]() -> ull
        {
            ull t = mrand();
            t <<= 32;
            t |= mrand();
            return t;
        };
        for (int i = 1; i <= n; ++i)
        {
            A[i] = rd();
            int t = numer[i] = ++num[A[i]];
            pos[{A[i], t}] = i;
            if (t > k)
                Hash[i] = Hash[pos[{A[i], t - k}]];
            else if (t == k)
                Hash[i] = total[A[i]];
            else
                total[A[i]] ^= Hash[i] = RAND();
        }
        vector<ull> sum(n + 1);
        ll ans = 0;
        int now = 0;
        ++cnt[0];
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = sum[i - 1] ^ Hash[i];
            ans += cnt[sum[i]]++;
            if (numer[i] > k)
            {
                int p = pos[{A[i], numer[i] - k}] - 1;
                while (now <= p)
                    --cnt[sum[now++]];
            }
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
