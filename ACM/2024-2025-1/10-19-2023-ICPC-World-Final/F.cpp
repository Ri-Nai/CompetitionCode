#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define End(x) return cout << (x) << endl, 0
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    // vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    struct Rect
    {
        int n, m;
        vector<vector<int>> val;
        Rect(int _, int __)
        {
            n = _, m = __;
            val.assign(n + 1, vector<int>(m + 1));
        }
        void input()
        {
            char *s = new char[m + 10];
            for (int i = 1; i <= n; ++i)
            {
                scanf("%s", s + 1);
                for (int j = 1; j <= m; ++j)
                    if (s[j] != '.')
                        val[i][j] = s[j];
            }
        }
        void swipe(int dir)
        {
            switch (dir)
            {
            case 0:
                for (int i = 1; i <= n; ++i)
                {
                    int now = 0;
                    for (int j = 1; j <= m; ++j)
                        if (val[i][j])
                            val[i][++now] = val[i][j];
                    for (int j = now + 1; j <= m; ++j)
                        val[i][j] = 0;
                }
                break;
            case 1:
                for (int i = 1; i <= m; ++i)
                {
                    int now = 0;
                    for (int j = 1; j <= n; ++j)
                        if (val[j][i])
                            val[++now][i] = val[j][i];
                    for (int j = now + 1; j <= n; ++j)
                        val[j][i] = 0;
                }
                break;
            case 2:
                for (int i = 1; i <= n; ++i)
                {
                    int now = m;
                    for (int j = m; j >= 1; --j)
                        if (val[i][j])
                            val[i][now--] = val[i][j];
                    for (int j = now; j >= 1; --j)
                        val[i][j] = 0;
                }
                break;
            case 3:
                for (int i = 1; i <= m; ++i)
                {
                    int now = n;
                    for (int j = n; j >= 1; --j)
                        if (val[j][i])
                            val[now--][i] = val[j][i];
                    for (int j = now; j >= 1; --j)
                        val[j][i] = 0;
                }
                break;
            }
            // return ans;
        }
        bool operator==(const Rect &_) const
        {
            return val == _.val;
        }

    } from(n, m), to(n, m);
    from.input();
    to.input();
    if (from == to)
        End("yes");
    int limit = 7e7 / n / m;
    auto run = [&](array<int, 4> dirs)
    {
        auto running = from;
        for (int k = 0; k <= limit; ++k)
        {
            int d = dirs[k % 4];
            running.swipe(d);
            if (running == to)
                return true;
        }
        return false;
    };
    for (int i : {0, 2})
        for (int j : {3, 1})
        {
            array<int, 4> dirs = {i, j, 2 - i, 4 - j};
            if (run(dirs))
                End("yes");
            dirs = {j, i, 4 - j, 2 - i};
            if (run(dirs))
                End("yes");
        }

    // End({"no", "yes"}[rand() % 2]);
        End("no");
}
