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
        const int maxn = 15;
        struct Team
        {
            string name;
            int num, penalty;
            void read()
            {
                char s[maxn];
                scanf("%s", s);
                name = s;
                num = rd(), penalty = rd();
            }
            bool operator < (const Team &_)
            {
                if (num == _.num)
                    return penalty < _.penalty;
                return num > _.num;
            }
        };
        vector<Team>A, B, t1, t2;
        int n = rd();
        const string TEAM = "lzr010506";
        map<string, int>cnt;
        for (int i = 1; i <= n; ++i)
        {
            Team Tmp;
            Tmp.read();
            A.push_back(Tmp);
            ++cnt[Tmp.name];
            if (Tmp.name == TEAM)
                t1.push_back(Tmp);
        }
        int m = rd();
        for (int i = 1; i <= m; ++i)
        {
            Team Tmp;
            Tmp.read();
            B.push_back(Tmp);
            ++cnt[Tmp.name];
            if (Tmp.name == TEAM)
                t2.push_back(Tmp);
        }
        for (auto x : A)
            if (cnt[x.name] == 1)
                t1.push_back(x);
        for (auto y : B)
            if (cnt[y.name] == 1)
                t2.push_back(y);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        int ans = min(n, m);
        for (int i = 0; i < t1.size(); ++i)
        {
            if (t1[i].name == TEAM)
                ans = min(ans, i  + 1);
            // cout << t1[i].name << ' ' << t1[i].num << ' ' << t1[i].penalty << '\n';
        }
        for (int i = 0; i < t2.size(); ++i)
        {
            if (t2[i].name == TEAM)
                ans = min(ans, i  + 1);
            // cout << t2[i].name << ' ' << t2[i].num << ' ' << t2[i].penalty << '\n';

        }
        cout << ans << '\n';
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
