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
        vector<vector<int>> A(20, vector<int>(20));
        string s;
        for (int i = 1; i <= 9; ++i)
        {
            cin >> s;
            for (int j = 0; j < s.size(); ++j)
                A[i][j + 1] = s[j] - '0';
        }
        auto B = A;
        const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
        const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
        bool flag = 0;
        for (int i = 1; i <= 9; ++i)
        {
            for (int j = 1; j <= 9; ++j)
            {
                if (i == 1 || i == 9 || j == 1 || j == 9 || A[i][j] != 8 || flag)
                    putchar('*');
                else putchar('8'), flag = 1;
            }
            puts("");
        }
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
