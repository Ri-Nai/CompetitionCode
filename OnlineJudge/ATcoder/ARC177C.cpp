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
        int n = rd();
        vector<vector<int> >M(n), mark(n);
        for (int i = 0; i < n; ++i)
        {
            M[i].assign(n, 0);
            mark[i].assign(n, -1);
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j)
                M[i][j] = s[j] == 'B';
        }
        auto get_ans = [&] (int x1, int y1, int x2, int y2, int now)
        {
            queue<pair<int, int> >Q, nxt;
            Q.push({x1, y1});
            auto dep = mark;
            dep[x1][y1] = 0;
            auto not_in = [&] (int x, int y)
            {
                return x >= n || y >= n || x < 0 || y < 0;
            };
            while(1)
            {
                const int dx[] = {0, 1, 0, -1};
                const int dy[] = {1, 0, -1, 0};
                auto clear_que = [&](auto &que)
                {
                    bool flag = 1;
                    // if ((&que) == (&nxt))
                    // {
                    //     cout << "1\n";
                    // }
                    // else cout << "2\n";
                    while (!que.empty())
                    {
                        auto [x, y] = que.front();
                        que.pop();
                        flag = 0;
                        for (int i = 0; i < 4; ++i)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if (not_in(nx, ny))
                                continue;
                            int nxt_val = dep[x][y] + (M[nx][ny] != now);
                            if (dep[nx][ny] != -1 && dep[nx][ny] <= nxt_val)
                                continue;
                            dep[nx][ny] = nxt_val;
                            if (M[nx][ny] == now)
                                Q.push({nx, ny});
                            else
                                nxt.push({nx, ny});
                        }
                    }
                    // for (int i = 0; i < n; ++i)
                    //     for (int j = 0; j < n; ++j)
                    //         cout << dep[i][j] << " \n"[j == n - 1];
                    return flag;
                };
                clear_que(nxt);
                if(clear_que(Q)) break;
                // for (int i = 0; i < n; ++i)
                //     for (int j = 0; j < n; ++j)
                //         cout << dep[i][j] << " \n"[j == n - 1];
            }
            // cout << now << "!!!!\n";
            // for (int i = 0; i < n; ++i)
            //     for (int j = 0; j < n; ++j)
            //         cout << M[i][j] << " \n"[j == n - 1];


            // cout << now << '\n';
            return dep[x2][y2];
        };
        cout << get_ans(0, 0, n - 1, n - 1, 0) + get_ans(0, n - 1, n - 1, 0, 1) << '\n';
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
