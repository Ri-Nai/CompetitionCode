#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
bool Nai;
namespace T
{
    void solve()
    {
        string s;
        cin >> s;
        int n = s.size();
        int pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ':')
            {
                cout << '\n';
                pos = i + 3;
                break;
            }
            cout << s[i];
        }
        int last = 0;
        for (int i = pos; i <= n; ++i)
        {
            if (s[i] == '/')
            {
                cout << '\n';
                last = i + 1;
                break;
            }
            cout << s[i];
        }
        int flag = 0;
        for (int i = pos; i < n; ++i)
        {
            if (s[i] == '/')
            {
                if (flag == 1 && s[last] != '=' && s[i - 1] != '=')
                {
                    for (int j = last; j < i; ++j)
                        cout << s[j];
                    cout << '\n';
                }
                last = i + 1;
                flag = 0;
            }
            if (s[i] == '=')
                ++flag;
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
