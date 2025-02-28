#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = opt<int>("n", 5);
    int m = opt<int>("m", min(2e5, (rnd.next() + 0.5) * n));
    int total = opt<int>("t", min(int(2e5), rnd.wnext(1, 8 * n, 0.3)));
    double ratio = opt<double>("r", .1);
    auto id = rnd.perm(n);
    cout << n << '\n';
    vector<vector<int>>E(n);
    for (int i = 0; i < m; ++i)
    {
        int v = rnd.next(0, n - 1);
        if (rnd.next() < ratio)
            E[v].push_back(rnd.wnext(min(v + 1, n - 1), n - 1, 1));
        else
            E[v].push_back(rnd.wnext(0, max(v - 1, 0), -1));
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (E[i].size()) ++cnt;
    for (int i = 0; i < n; ++i)
    {
        int p = id[i];
        if (E[p].size())
        {
            cout << 2 << ' ' << E[p].size();
            for (int f : E[p])
                cout << ' ' << id[f] + 1;
            cout << '\n';
        }
        else
        {
            int length = rnd.wnext(1, max(1, total / (cnt + 1)), 2);
            vector<string> S = {"s", "y", "o", "o", "S", "soyo", "oyo", "yo", "so", "soyo", "soyo", "soyo", "soyo"};
            string now = "";
            if (rnd.next() < 0.3)
            {
                now += "y";
                if (rnd.next() < 0.3)
                    now += "o";
            }
            while (now.size() < length)
            {
                if (rnd.next() > 0.3)
                    now += rnd.any(S);
                else now += rnd.next("[a-zA-Z]{1, 1}");
            }
            if (rnd.next() < 0.3)
                now += "s";
            if (rnd.next() < 0.3)
                now += "o";
            cout << 1 << ' ' << now << "\n";
        }
    }
}
