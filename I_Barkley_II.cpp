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
namespace vio
{

}
namespace T
{
    void solve()
    {
        int n = rd(), m = rd();
        struct BIT
        {
            vector<int> C;
            int n;
            BIT(int len) : n(len), C(len + 1) {}
            void Add(int x, int y)
            {
                while (x <= n)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
        } Tr(n);
        map<int, int> pre;
        vector<int> A(n + 1);
        vector<int> nxt(n + 1);
        vector<tuple<int, int, int>> Q;
        set<int> S;
        for (int i = 1; i <= n; ++i)
        {
            A[i] = rd();
            S.insert(A[i]);
            nxt[pre[A[i]]] = i;
            if (!pre[A[i]])
                Tr.Add(i, 1);
            Q.emplace_back(pre[A[i]] + 1, i - 1, A[i]);
            pre[A[i]] = i;
        }
        int flag = 0;
        int mex = 1;
        while (S.count(mex))
            ++mex;
        Q.emplace_back(1, n, mex);
        for (int i = n; i >= 1; --i)
            if (i == pre[A[i]])
                Q.emplace_back(i + 1, n, A[i]);
        sort(Q.begin(), Q.end());
        int idx = 1;
        int ans = -1;
        for (auto [l, r, x] : Q)
        {
            if (r - l < 0)
                continue;
            while (idx < l)
            {
                if (nxt[idx])
                    Tr.Add(nxt[idx], 1);
                Tr.Add(idx++, -1);
            }
            ans = max(Tr.Sum(r) - Tr.Sum(l - 1) - x, ans);
        }
        cout << ans << '\n';
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        T::solve();
}
