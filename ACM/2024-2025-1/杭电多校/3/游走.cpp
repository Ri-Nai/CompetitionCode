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
        int n = rd(), m = rd();
        const int inf = 1e9 + 7;
        bool flag = 0;
        vector<vector<int>> T(m + 1);
        vector<int>ops;
        for (int i = 1; i <= m; ++i)
        {
            int op = rd();
            if (op == 0)
            {
                int p = rd(), q = rd();
                auto check = [&](int t, int tar, int pos)
                {
                    int sep = tar - t;
                    for (int i = 1; ; ++i)
                    {
                        int now = i / 2;
                        int type = i & 1;
                        int length;
                        if (type)
                            length = pos - 1 + now * (n - 1) * 2;
                        else
                            length = 2 * now * (n - 1) - (pos - 1);
                        if (length > sep)
                            return 0;
                        if ((length & 1) == (sep & 1))
                            return 1;
                    }
                };
                vector<int>tmp;
                for (int j = 0; j <= q; ++j)
                    if (check(j, q, p))
                    {
                        cout << j << ' ' << q << ' ' << p << '\n';
                        tmp.push_back(j);
                    }
                if (ops.size() != 0)
                {
                    for (auto x : T[ops.back()])
                        for (auto y : tmp)
                            if (x == y)
                                T[i].push_back(x);
                    if (T[i].size() == 0)
                        flag = 1;
                }
                else T[i] = tmp;
                ops.push_back(i);
            }
            else
            {
                if (flag)
                    cout << "bad" << endl;
                else if (ops.size() == 0)
                    cout << (op == 1 ? "0" : "inf") << endl;
                else
                {
                    auto now = T[ops.back()];
                    cout << (op == 1 ? now[0] : now.back()) << endl;
                }
            }
        }
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
