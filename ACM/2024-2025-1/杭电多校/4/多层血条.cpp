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
    void print(int n, int m, string s)
    {
        cout << "+" + string(m, '-') + "+" << '\n';
        for (int i = 1; i <= n; ++i)
            cout << "|" + s + "|" << '\n';
        cout << "+" + string(m, '-') + "+" << '\n';
    }
    char Get(int num)
    {
        if (num == 0)
            return ' ';
        return 'A' + (num - 1) % 5;
    }
    void solve()
    {
        int n = rd(), m = rd(), hp = rd(), dmg = rd();
        if (dmg >= m)
        {
            print(n, m, string(m, '.'));
            return;
        }
        int num = hp % m;
        int total = hp / m;
        string s(m, '.');
        for (int j = 0; j < m; ++j)
            if (j < num)
                s[j] = Get(total + 1);
            else s[j] = Get(total);
        int cost = dmg;
        for (int j = num - 1; cost > 0 && j >= 0; --cost, --j)
            s[j] = '.';
        for (int j = m - 1; cost > 0 && j >= 0; --cost, --j)
            s[j] = '.';
        print(n, m, s);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    cout << (1 << 31) << '\n';
    int t; cin >> t; while(t--)
    T::solve();
}
