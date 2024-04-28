#include <bits/stdc++.h>
using namespace std;
const int P = 19260817;
typedef unsigned long long ull;
ull get(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i == 0 && s[i] != ' ' || s[i - 1] == ' ' && s[i] != ' ')
            res = res * P + s[i];
    }
    return res;
}
int main()
{

    int n;
    cin >> n;
    getchar();
    map<ull, multiset<string>> mp;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        getline(cin, s);
        mp[get(s)].insert(s);
    }
    int m;
    cin >> m;
    getchar();
    while (m--)
    {
        string s;
        getline(cin, s);
        ull hash = get(s);
        if (mp.count(hash) == 0)
            cout << s << '\n';
        else
        {
            auto S = mp[hash];
            int cnt = 0;
            for (auto x : S)
                cout << x << "|\n"[++cnt == S.size()];
        }
    }
}
