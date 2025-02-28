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
        // vector<string> has(n);
        vector<int> lens(n);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            lens[i] = s.size();
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((sum += lens[i]) > m)
                End(i);
        }
        End(n);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
