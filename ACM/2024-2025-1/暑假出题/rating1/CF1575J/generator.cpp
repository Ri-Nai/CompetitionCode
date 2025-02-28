#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 50; i++)
    {
        startTest(i);
        int n, m, k;
        if (i <= 10)
        {
            n = rnd.next(3, 10);
            m = rnd.next(3, 10);
            k = rnd.next(5, 10);
        }
        else if (i <= 20)
        {
            n = rnd.next(3, 200);
            m = rnd.next(3, 200);
            k = rnd.next(50, 100);
        }
        else if (i <= 35)
        {
            n = rnd.next(3, 1000);
            m = 1e6 / n;
            k = 1e6 - rnd.wnext(1, 1000, -10);
        }
        else
        {
            m = rnd.next(3, 1000);
            n = 1e6 / m;
            k = 1e6 - rnd.wnext(1, 1000, -10);
        }
        cout << n << ' ' << m << ' ' << k << endl;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                double t = rnd.next();
                int now = 2;
                if (j != m && t < 0.4)
                    now = 1;
                else if (j != 1 && t > 0.6)
                    now = 3;
                cout << now << " \n"[j == m];
            }
        for (int j = 1; j <= k; ++j)
            cout << rnd.next(1, n) << ' ' << rnd.next(1, m) << '\n';
    }
    return 0;
}
