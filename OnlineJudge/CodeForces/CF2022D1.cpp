#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
#define endAsk(i) return cout << "! " << (i) << endl, void()
bool Nai;
namespace T
{
    void solve()
    {
        int n;
        cin >> n;
        auto ask = [&](int i, int j)
        {
            cout << "? " << i << ' ' << j << endl;
            int res;
            cin >> res;
            if (res == -1)
                exit(0);
            return res;
        };
        pair<int, int> may{};
        int think = 0;
        for (int i = 1; !may.first && i + 1 <= n; i += 2)
            if ((think = ask(i, i + 1)) != ask(i + 1, i))
                may = {i, i + 1};
        if ((think = ask(1, n)) != ask(n, 1))
            may = {1, n};
        vector<int> other;
        for (int i = 1; i <= n; ++i)
            if (i != may.first && i != may.second)
                other.push_back(i);
        bool hasKnight = ask(other.front(), may.first) == ask(other.front(), may.second);
        if (hasKnight)
            if (think)
                endAsk(may.second);
            else
                endAsk(may.first);
        else
            if (ask(may.first, may.second))
                endAsk(may.first);
            else endAsk(may.second);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
/*
Knight Kight
Y Y
Knight Knave
N N
Knight I
Y N
Knave Knave
Y Y
Knave I
N Y
*/
