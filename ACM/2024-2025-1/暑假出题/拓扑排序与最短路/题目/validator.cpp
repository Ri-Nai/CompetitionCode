#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1e6, "testCount");
    inf.readEoln();
    long long sum = 0;
    long long total = 0;
    for (int i = 1; i <= n; ++i)
    {
        int opt = inf.readInt(1, 2, "opt");
        inf.readSpace();
        if (opt == 1)
        {
            string s = inf.readToken("[a-zA-Z]{1, 1000000}", "s");
            total += s.length();
        }
        else
        {
            int m = inf.readInt(1, 1e6, "m");
            sum += m;
            for (int j = 1; j <= m; ++j)
            {
                inf.readSpace();
                int t = inf.readInt(1, n, "fa_i_j");
            }
        }
        inf.readEoln();
    }
    ensuref(sum <= 1e6, "sum exceed");
    ensuref(total <= 1e6, "total exceed");
    inf.readEof();
}
