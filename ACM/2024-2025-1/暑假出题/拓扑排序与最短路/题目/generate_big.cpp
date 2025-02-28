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
    cout << n << '\n';
    vector<int> cnt(n + 1);
    for (int i = 1; i < m - 2; ++i)
    {
        int t = rnd.next(4, n);
        ++cnt[t];
    }
    cout << "1 so\n1 yo\n1 soyo\n";
    for (int i = 4; i < n; ++i)
        cout << 2 << ' ' << 2 << ' ' << rnd.wnext(1, i - 1, 2) << ' ' << rnd.wnext(1, i - 1, 2) << '\n';
    cout << 2 << ' ' << 2 << ' ' << n << ' ' << n - 1 << '\n';

}
