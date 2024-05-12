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
        vector<int> Price({1, 5, 10, 50, 100, 500});
        vector<int> num(6);
        int m = 6;
        for (int i = 0; i < m; ++i)
            num[i] = rd();
        reverse(Price.begin(), Price.end());
        reverse(num.begin(), num.end());
        int n = rd();
        vector<int> A;
        for (int i = 0; i < n; ++i)
        {
            A.push_back(rd());
        }
        for (auto x : A)
        {
            for (int j = 0; j < m; ++j)
            {
                int t = min(x / Price[j], num[j]);
                num[j] -= t;
                x -= t * Price[j];
            }
            if(x)End("No");
        }
        End("Yes");
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
