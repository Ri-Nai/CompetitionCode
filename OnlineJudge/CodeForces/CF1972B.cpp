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
        string s;
        int m;
        cin >> m;
        cin >> s;
        bool now = 1;
        vector<int> A;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == 'U')A.push_back(1);
            else A.push_back(0);
        while (1)
        {
            bool flag = 0;
            int n = A.size();
            vector<int>B;
            for (int i = 0; i < n; ++i)
            {
                if (A[i])
                {
                    flag = 1;
                    A[(i + 1) % n] ^= 1;
                    A[(i - 1 + n) % n] ^= 1;
                    for (int j = 0; j < i; ++j)
                        B.push_back(A[j]);
                    for (int j = i + 1; j < n; ++j)
                        B.push_back(A[j]);
                    break;
                }
            }
            if (!flag)
            {
                cout << (now ? "NO" : "YES") << '\n';
                return ;
            }
            now ^= 1;
            A = B;
        }

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
