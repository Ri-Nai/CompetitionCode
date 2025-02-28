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
    vector<int> id;
    auto Pre(int n)
    {
        vector<int> Pr;
        vector<int> P(n + 1);
        P[1] = 1;
        int tot = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (!P[i])
                P[i] = ++tot;
            for (int j = i + i; j <= n; j += i)
                if (!P[j])
                    P[j] = P[i];
        }
        return P;
    }
    void init()
    {
        id = Pre(1e7);
    }
    int get_id(int x)
    {
        if (x & 1)
            return id[x];
        return 0;
    }
    void solve()
    {
        int res = 0;
        int n = rd();
        while (n--)
            res ^= get_id(rd());
        if (res)
            End("Alice");
        else End("Bob");
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
