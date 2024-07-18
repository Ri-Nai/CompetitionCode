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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> A;
        for (int i = 0; i < n; ++i)
        {
            if (i && s[i] == '0' && s[i - 1] == '0')
                continue;
            A.push_back(s[i] - 48);
        }
        n = A.size();
        int now = 0;
        for (int i = 0; i < n; ++i)
            if (A[i]) ++now;
            else --now;
        cout << (now > 0 ? "Yes" : "No") << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
