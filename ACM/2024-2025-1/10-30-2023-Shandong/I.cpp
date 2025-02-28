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
        int n, m;
        cin >> n >> m;
        auto modify = [&](pair<int, int> &x, int y)
        {
            if (y == 1 || y == 4)
                x.first += y;
            else x.second += y;
        };
        map<pair<int, int>, int> mark;
        for (int i = 1; i <= 6; ++i)
            for (int j = 1; j <= 6; ++j)
                for (int k = 1; k <= 6; ++k)
                {
                    pair<int, int> res;
                    res.first = res.second = 0;
                    modify(res, i);
                    modify(res, j);
                    modify(res, k);
                    mark[res] = 1;
                }
        if (mark[{n, m}])
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
        T::solve();
}
