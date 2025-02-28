#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 30; i++)
    {
        startTest(i);
        int n, m;
        if (i <= 5)
            n = rnd.next(3, 5);
        else if (i <= 10)
            n = rnd.next(6, 10);
        else if (i <= 15)
            n = rnd.next(10, 15);
        else
            n = 20;
        m = rnd.next(n, n * n);
        if (n == 20)
            m = rnd.next(300, 400);
        cout << n << ' ' << m << '\n';
        for (int i = 2; i <= n; ++i)
            cout << i << ' ' << rnd.next(1, i - 1) << ' ' << rnd.next(1, int(1e9)) << '\n';
        for (int i = n; i <= m; ++i)
            cout << rnd.next(1, n) << ' ' << rnd.next(1, n) << ' ' << rnd.next(1, int(1e9)) << '\n';
    }
    return 0;
}
