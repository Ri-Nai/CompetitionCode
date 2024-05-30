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
        string s;
        cin >> s;
        vector<int> move(256);
        for (auto c : s)
            ++move[c];
        int x = move['E'] - move['W'];
        int y = move['N'] - move['S'];
        if (abs(x) & 1 | abs(y) & 1)
            End("NO");
        if (x == 0 && y == 0 && move['E'] == 1 && move['N'] == 0)
            End("NO");
        if (y == 0 && x == 0 && move['N'] == 1 && move['E'] == 0)
            End("NO");
        int nowx = 0, nowy = 0;
        // cout << x << ' ' << y << '\n';
        move.assign(256, 0);
        bool flag = 0;
        for (auto c : s)
        {
            if (x < 0 && c == 'W' && nowx < -x / 2)
                ++nowx, putchar('R');
            else if (x > 0 && c == 'E' && nowx < x / 2)
                ++nowx, putchar('R');
            else if (y < 0 && c == 'S' && nowy < -y / 2)
                ++nowy, putchar('R');
            else if (y > 0 && c == 'N' && nowy < y / 2)
                ++nowy, putchar('R');
            else if (x == 0 && y == 0 && (c == 'W' || c == 'E') && ++move[c] == 1)
                putchar('R');
            else if (x == 0 && y == 0 && (c == 'N' || c == 'S') && ++move[c] == 1)
                putchar('H'), flag = 1;
            else if (x == 0 && (c == 'W' || c == 'E') && ++move[c] == 1)
                putchar('R');
            else if (y == 0 && (c == 'N' || c == 'S') && ++move[c] == 1)
                putchar('R');
            else putchar(flag ? 'R' : 'H');
        }
        puts("");
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
