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
        int k = rd();
        --k;
        int total = 0;
        vector<string> ans;
        auto run = [&](auto &&self, int now, int show) -> void
        {
            if (now == 0)
                return;
            if (now % 4 == 2)
            {
                self(self, now - 2 >> 1, show);
                int x = ++total;

                if (show)
                    printf("POP %d GOTO %d; PUSH %d GOTO %d\n", x, x + 1, x, 1);
            }
            else
            {
                self(self, now - 2, show);
                int x = ++total;

                if (show)
                    printf("POP %d GOTO %d; PUSH %d GOTO %d\n", x, x + 1, x, x);
            }
        };
        run(run, k, 0);
        cout << total + 1 << endl;
        total = 0;
        run(run, k, 1);
        printf("HALT; PUSH 114 GOTO 1\n");
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
