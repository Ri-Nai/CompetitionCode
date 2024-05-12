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
        string S, T;
        cin >> S >> T;
        vector<int>ans;
        for (int i = 0, j = 0; i < S.size(); ++i, ++j)
        {
            while (T[j] != S[i]) ++j;
            ans.push_back(j + 1);
        }
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    // int t; cin >> t; while(t--)
    T::solve();
}
