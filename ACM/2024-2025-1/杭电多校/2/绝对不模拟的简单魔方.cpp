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
    vector<vector<pair<int, int>>> point;
    struct rotate
    {
        vector<int> X;
        vector<int> Y;
        vector<int> topX, topY;
        rotate(vector<int> P, vector<int> Q)
        {
            assert(P.size() == 24);
            assert(Q.size() == 16);
            for (int i = 0; i < P.size(); ++i)
                if (i & 1)
                    Y.push_back(P[i]);
                else
                    X.push_back(P[i]);
            for (int i = 0; i < Q.size(); ++i)
                if (i & 1)
                    topY.push_back(Q[i]);
                else
                    topX.push_back(Q[i]);
        }
        vector<string> work(vector<string> now, int p)
        {
            auto res = now;
            for (int i = 0; i < 12; ++i)
            {
                int nx = X[i], ny = Y[i];
                int tx = X[(i + p * 3 + 12) % 12], ty = Y[(i + p * 3 + 12) % 12];
                res[nx][ny] = now[tx][ty];
            }
            for (int i = 0; i < 8; ++i)
            {
                int nx = topX[i], ny = topY[i];
                int tx = topX[(i + p * 2 + 8) % 8], ty = topY[(i + p * 2 + 8) % 8];
                res[nx][ny] = now[tx][ty];
            }
            return res;
        }
    };
    vector<rotate> op;
    vector<string> complete(10, string(13, '*'));
    void show(vector<string> now, vector<string> tmp = vector<string>(10, ""))
    {
        for (int i = 1; i <= 9; ++i)
            cout << now[i] + tmp[i]<< '\n';
        cout << "-----------\n";
    }
    void init()
    {
        point.push_back({{3, 4}, {4, 3}, {4, 4}});
        point.push_back({{6, 3}, {6, 4}, {7, 4}});
        point.push_back({{3, 6}, {4, 6}, {4, 7}});
        point.push_back({{6, 6}, {6, 7}, {7, 6}});

        point.push_back({{1, 4}, {4, 1}, {4, 12}});
        point.push_back({{6, 1}, {9, 4}, {6, 12}});
        point.push_back({{1, 6}, {4, 9}, {4, 10}});
        point.push_back({{9, 6}, {6, 9}, {6, 10}});

        op.emplace_back(vector<int>{3, 6, 2, 6, 1, 6, 6, 6, 5, 6, 4, 6, 9, 6, 8, 6, 7, 6, 4, 10, 5, 10, 6, 10},
                        vector<int>{4, 7, 5, 7, 6, 7, 6, 8, 6, 9, 5, 9, 4, 9, 4, 8});

        op.emplace_back(vector<int>{3, 4, 2, 4, 1, 4, 6, 4, 5, 4, 4, 4, 9, 4, 8, 4, 7, 4, 4, 12, 5, 12, 6, 12},
                        vector<int>{4, 3, 5, 3, 6, 3, 6, 2, 6, 1, 5, 1, 4, 1, 4, 2});

        op.emplace_back(vector<int>{3, 4, 3, 5, 3, 6, 4, 7, 5, 7, 6, 7, 7, 6, 7, 5, 7, 4, 6, 3, 5, 3, 4, 3},
                        vector<int>{4, 4, 4, 5, 4, 6, 5, 6, 6, 6, 6, 5, 6, 4, 5, 4});

        op.emplace_back(vector<int>{1, 4, 1, 5, 1, 6, 4, 9, 5, 9, 6, 9, 9, 6, 9, 5, 9, 4, 6, 1, 5, 1, 4, 1},
                        vector<int>{4, 12, 4, 11, 4, 10, 5, 10, 6, 10, 6, 11, 6, 12, 5, 12});

        op.emplace_back(vector<int>{4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7, 4, 8, 4, 9, 4, 10, 4, 11, 4, 12},
                        vector<int>{3, 4, 3, 5, 3, 6, 2, 6, 1, 6, 1, 5, 1, 4, 2, 4});

        op.emplace_back(vector<int>{6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 6, 6, 6, 7, 6, 8, 6, 9, 6, 10, 6, 11, 6, 12},
                        vector<int>{7, 4, 7, 5, 7, 6, 8, 6, 9, 6, 9, 5, 9, 4, 8, 4});
        for (int i = 1; i <= 3; ++i)
            for (int j = 4; j <= 6; ++j)
                complete[i][j] = '1';
        for (int i = 7; i <= 9; ++i)
            for (int j = 4; j <= 6; ++j)
                complete[i][j] = '6';
        for (int i = 4; i <= 6; ++i)
            for (int j = 1; j <= 12; ++j)
                complete[i][j] = '0' + (j + 5) / 3;
    }
    int flag;
    vector<char> ans;
    int check(vector<string> now)
    {
        int cnt = 0;
        for (int i = 1; i <= 9; ++i)
            for (int j = 1; j <= 12; ++j)
                cnt += complete[i][j] != now[i][j];
        return cnt;
    }
    void dfs(int cnt, vector<string> now)
    {
        if (flag)
            return;
        int get = check(now);
        if (get == 0)
        {
            flag = 1;
            return ;
        }
        else if (get == 2)
        {
            flag = 2;
            for (auto v : point)
            {
                int num = 0;
                for (auto [x, y] : v)
                    num += now[x][y] != complete[x][y];
                if (num == 2)
                {
                    for (auto [x, y] : v)
                        ans.push_back(now[x][y]);
                    sort(ans.begin(), ans.end());
                }
            }
            return ;
        }
        if (cnt == 3)
            return;
        for (int i = -1; i <= 1; i += 2)
            for (auto r : op)
                dfs(cnt + 1, r.work(now, i));
    }
    void solve()
    {
        flag = 0;
        ans.clear();
        vector<string>Map(1, string(13, '*'));
        for (int i = 0; i < 9; ++i)
        {
            string s = "*";
            string t;
            cin >> t;
            s += t;
            Map.push_back(s);
        }
        dfs(0, Map);
        if (flag == 1)
            cout << "No problem\n";
        else for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " \n"[i == 2];

    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    T::init();
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
/*
9*12

*/
