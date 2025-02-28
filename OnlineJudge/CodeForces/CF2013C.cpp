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
        auto query = [&](const string &t)
        {
            cout << "? " << t << endl;
            int ans;
            cin >> ans;
            return ans;
        };
        auto write_ans = [&](const string &t)
        {
            cout << "! " << t << endl;
        };
        string now = "";
        int flag = 0;
        srand(time(0));
        if (n == 1)
        {
            if (query("0"))
                write_ans("0");
            else
                write_ans("1");
            return;
        }
        if (n == 2)
        {
            vector<string> base{"00", "01", "10", "11"};
            for (auto s : base)
                if (query(s))
                {
                    write_ans(s);
                    return;
                }
        }
        if (!query(now = "01"))
            if (!query(now = "10"))
            {
                if (query("0"))
                    write_ans(string(n, '0'));
                else
                    write_ans(string(n, '1'));
                return;
            }
        while (true)
        {
            if (now.size() == n)
                break;
            if (!flag)
            {
                int p = rand() & 1;
                char c = '0' + p;
                string nxt_0 = now + c;
                int res = query(nxt_0);
                if (res == -1)
                    return;
                if (res)
                {
                    now = nxt_0;
                    continue;
                }
                c ^= 1;
                string nxt_1 = now + c;
                res = query(nxt_1);
                if (res == -1)
                    return;
                if (res)
                {
                    now = nxt_1;
                    continue;
                }
                flag = 1;
            }
            else
            {
                int p = rand() & 1;
                char c = '0' + p;
                string nxt_0 = c + now;
                int res = query(nxt_0);
                if (res == -1)
                    return;
                if (res)
                {
                    now = nxt_0;
                    continue;
                }
                c ^= 1;
                string nxt_1 = c + now;
                res = query(nxt_1);
                if (res == -1)
                    return;
                if (res)
                {
                    now = nxt_1;
                    continue;
                }
            }
        }
        write_ans(now);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
/*
? 01
0
? 10
1
? 101
0
? 100
1
? 1000
0
? 1001
0
? 1100
1
 */
