#include <bits/stdc++.h>
using namespace std;
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
namespace NTT
{
    const int P = 998244353;
    int Qpow(int x, int n)
    {
        int res = 1;
        for (; n; n >>= 1, x = 1ll * x * x % P)
            if (n & 1)
                res = 1ll * x * res % P;
        return res;
    }
    const int G = 114514, G_ = Qpow(G, P - 2);
    void Solve()
    {
        int n = rd(), m = rd();
        int T = 1, bit = 0;
        while (T <= n + m)
            T <<= 1, ++bit;
        vector<int> idx(T);
        for (int i = 1; i < T; ++i)
            idx[i] = idx[i >> 1] >> 1 | (i & 1) << bit - 1;
        vector<int> A, B, C;
        for (int i = 0; i <= n; ++i)
            A.push_back(rd());
        for (int i = 0; i <= m; ++i)
            B.push_back(rd());
        A.resize(T);
        B.resize(T);
        auto NTT = [&](vector<int> &T, int g)
        {
            int len = T.size();
            for (int i = 0; i < len; ++i)
                if (i < idx[i])
                    swap(T[i], T[idx[i]]);
            for (int p = 1, m = 1; m < len; ++p, m <<= 1)
            {
                int W0 = Qpow(g, (P - 1) >> p);
                for (int i = 0; i + m < len; i += m << 1)
                {
                    int W = 1;
                    for (int j = i; j < i + m; ++j, W = 1ll * W * W0 % P)
                    {
                        int X = T[j], Y = 1ll * W * T[j + m] % P;
                        T[j] = (X + Y) % P;
                        T[j + m] = (0ll + X - Y + P) % P;
                    }
                }
            }
        };
        NTT(A, G);
        NTT(B, G);
        for (int i = 0; i < T; ++i)
            C.push_back(1ll * A[i] * B[i] % P);
        NTT(C, G_);
        int inv = Qpow(T, P - 2);
        for (int i = 0; i <= n + m; ++i)
            printf("%lld ", 1ll * C[i] * inv % P);
    }
}
