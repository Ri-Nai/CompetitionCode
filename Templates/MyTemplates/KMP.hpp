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
    string a, b;
    void solve()
    {
        cin >> a >> b;
        vector <int> nxt(b.size());
        int now = 0;
        for (int i = 1; i < b.size(); ++i)
        {
            while (now && b[i] != b[now]) now = nxt[now - 1];
            if (b[i] == b[now])++now;
            nxt[i] = now;
        }
        now = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            while (now && a[i] != b[now]) now = nxt[now - 1];
            if (a[i] == b[now]) ++now;
            if (now == b.size())
            {
                cout << i - b.size() + 2 << '\n';
                now = nxt[now - 1];
            }
        }
        for (int i = 0; i < b.size(); ++i)
            cout << nxt[i] << " \n"[i == b.size() - 1];
    }
}
bool Ri;
