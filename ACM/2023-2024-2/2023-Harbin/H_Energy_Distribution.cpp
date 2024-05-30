#include <bits/stdc++.h>
using namespace std;
namespace T
{
    int n;
    const int N = 15;
    int w[N][N];
    long double A[N][N], ans;
    void check(int p)
    {
        vector<int> E;
        for (int i = 1; i <= n; ++i, p >>= 1)
            if (p & 1)
                E.push_back(i);
        int m = E.size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < i; ++j)
                A[i][j] = w[E[j]][E[i]];
            A[i][i] = 0;
            for (int j = i + 1; j < m; ++j)
                A[i][j] = w[E[i]][E[j]];
            A[i][m] = -1;
            A[i][m + 1] = 0;
        }
        for (int i = 0; i < m; ++i)
            A[m][i] = 1;
        A[m][m] = 0;
        A[m][m + 1] = 1;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = i + 1; j <= m; ++j)
                if (fabs(A[i][i]) < fabs(A[j][i]))
                    swap(A[i], A[j]);
            if (fabs(A[i][i]) < 1e-9)
                return;
            for (int j = i + 1; j <= m; ++j)
            {
                double tmp = A[j][i] / A[i][i];
                for (int k = i; k <= m + 1; ++k)
                    A[j][k] -= tmp * A[i][k];
            }
        }
    }
    void solve()
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> w[i][j];
        int P = 1 << n;
        for (int i = 1; i < P; ++i)
            check(i);
        printf("%.10Lf\n", ans);
    }
}
int main()
{
    T::solve();
}
