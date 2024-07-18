#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pr;
#define End(X) return cout << (X) << '\n', void()
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
namespace FFT
{
    const double pi = asin(1) * 2;
    struct Comp
    {
        double a, b;
        Comp(double _ = 0, double __ = 0) : a(_), b(__) {}
        Comp operator+(const Comp &_) const
        {
            return {a + _.a, b + _.b};
        }
        Comp operator-(const Comp &_) const
        {
            return {a - _.a, b - _.b};
        }
        Comp operator*(const Comp &_) const
        {
            return {a * _.a - b * _.b, a * _.b + b * _.a};
        }
    };
    void solve()
    {
        int l1 = rd(), l2 = rd(), len = 1, bit = 0;
        while (len <= l1 + l2)
            len <<= 1, ++bit;
        vector<int> idx(len);
        for (int i = 1; i < len; ++i)
            idx[i] = idx[i >> 1] >> 1 | (i & 1) << bit - 1;
        vector<Comp> A, B, C;
        for (int i = 0; i <= l1; ++i)
            A.push_back({rd(), 0});
        for (int i = 0; i <= l2; ++i)
            B.push_back({rd(), 0});
        A.resize(len), B.resize(len);
        auto FFT = [&](auto self, vector<Comp> &T, int p) -> void
        {
            int n = T.size(), m = n >> 1;
            if (n == 1)
                return;
            vector<Comp> X, Y;
            for (int i = 0; i < n; i += 2)
                X.push_back(T[i]), Y.push_back(T[i | 1]);
            self(self, X, p);
            self(self, Y, p);
            Comp W0(cos(2 * pi / n), sin(2 * pi / n) * p), W(1, 0);
            for (int i = 0; i < m; ++i, W = W * W0)
                T[i] = X[i] + W * Y[i], T[i + m] = X[i] - W * Y[i];
        };
        auto FFT_ = [&](vector<Comp> &T, int p) -> void
        {
            int len = T.size();
            for (int i = 0; i < len; ++i)
                if (i < idx[i])
                    swap(T[i], T[idx[i]]);
            for (int m = 1; m < len; m <<= 1)
            {
                // cout<<m<<'\n';
                int n = m << 1;
                Comp W0(cos(2 * pi / n), sin(2 * pi / n) * p);
                for (int j = 0; j < len; j += n)
                {
                    Comp W(1, 0);
                    for (int i = j; i < j + m; ++i, W = W * W0)
                    {
                        Comp X = T[i], Y = W * T[i + m];
                        T[i] = X + Y, T[i + m] = X - Y;
                    }
                }
            }
        };
        FFT_(A, 1);
        FFT_(B, 1);
        for (int i = 0; i < len; ++i)
            C.push_back(A[i] * B[i]);
        FFT_(C, -1);
        for (int i = 0; i <= l1 + l2; ++i)
            printf("%d%c", int(C[i].a / len + 0.5), " \n"[i == l1 + l2]);
    }
}
