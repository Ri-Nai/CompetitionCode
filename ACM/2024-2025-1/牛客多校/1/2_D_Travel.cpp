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
void show(auto V)
{
    for (int i = 0; i < V.size(); ++i)
        cout << V[i] << " \n"[i == V.size() - 1];
}
namespace T
{
    void solve()
    {
        int X = rd(), Y = rd(), n = rd(), q = rd();
        struct Solution
        {
            int n, limit, len;
            vector<int> opt;
            vector<vector<int>> key, ans_pos;
            vector<vector<ll>> ans_step;
            Solution(int n_, int limit_) : n(n_), limit(limit_), len(sqrt(n))
            {
                int blk = n / len + 1;
                key = vector<vector<int>>(blk, {0, limit});
                ans_pos.resize(blk);
                ans_step.resize(blk);
                opt.assign(n + 1, 0);
            }
            void work_range(int l, int r, int &pos, ll &step)
            {
                int now = pos;
                for (int i = l; i <= r; ++i)
                {
                    int nxt = now + opt[i];
                    nxt = max(nxt, 0);
                    nxt = min(nxt, limit);
                    step += abs(now - nxt);
                    now = nxt;
                }
                pos = now;
            }
            void Build()
            {
                auto build_range = [&](int id, int l, int r)
                {
                    int now = 0;
                    int L = 0, R = 0;
                    auto &vec = key[id];
                    for (int i = l; i <= r; ++i)
                    {
                        now += opt[i];
                        if (-now > L)
                        {
                            L = -now;
                            if (R - L >= limit)
                                break;
                            vec.push_back(-now);
                        }
                        else if (now > R)
                        {
                            R = now;
                            if (R - L >= limit)
                                break;
                            vec.push_back(limit - now);
                        }
                    }
                    sort(vec.begin(), vec.end());
                    vec.erase(unique(vec.begin(), vec.end()), vec.end());
                    for (auto pos : vec)
                    {
                        ll step = 0;
                        work_range(l, r, pos, step);
                        ans_pos[id].push_back(pos);
                        ans_step[id].push_back(step);
                    }
                };
                int l = 1, r;
                while (l <= n)
                {
                    int id = l / len;
                    r = (id + 1) * len - 1;
                    if (r > n)
                        r = n;
                    build_range(id, l, r);
                    l = r + 1;
                }
            }
            void change(int &pos, ll &step, int ans_pos, ll ans_step)
            {
                pos = ans_pos;
                step += ans_step;
            }
            void work_block(int id, int &pos, ll &step)
            {
                auto &now = key[id];
                int m = now.size();
                int p = lower_bound(now.begin(), now.end(), pos) - now.begin();
                if (p == 0)
                    return change(pos, step, ans_pos[id][0], ans_step[id][0]);
                auto Get = [&](int l, int r, int p, auto L, auto R)
                {
                    return (R - L) / (r - l) * (p - l) + L;
                };
                change(pos, step,
                       Get(now[p - 1], now[p], pos, ans_pos[id][p - 1], ans_pos[id][p]),
                       Get(now[p - 1], now[p], pos, ans_step[id][p - 1], ans_step[id][p]));
            }
            void Solve(int l, int r, int &pos, ll &step)
            {
                work_range(l, min(l - l % len + len - 1, r), pos, step);
                for (l = l - l % len + len; l + len - 1 <= r; l += len)
                    work_block(l / len, pos, step);
                work_range(l, r, pos, step);
            }
        } SX(n, X), SY(n, Y);
        for (int i = 1; i <= n; ++i)
        {
            char c = getchar();
            int t = rd();
            if (c == 'L')
                SX.opt[i] = -t;
            else if (c == 'R')
                SX.opt[i] = t;
            else if (c == 'D')
                SY.opt[i] = -t;
            else
                SY.opt[i] = t;
        }
        SX.Build(), SY.Build();
        for (int x, y, l, r; q--;)
        {
            ll ans = 0;
            x = rd(), y = rd(), l = rd(), r = rd();
            SX.Solve(l, r, x, ans);
            SY.Solve(l, r, y, ans);
            cout << x << ' ' << y << ' ' << ans << '\n';
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
