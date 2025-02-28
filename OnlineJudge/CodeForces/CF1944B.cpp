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
namespace T
{
    void solve()
    {
        int n = rd(), k = rd();
        int m = n << 1;
        vector<int> A(m + 1);
        for (int i = 1; i <= m; ++i)
            A[i] = rd();
        vector<int> cnt(n + 1);
        vector<int> extra(n + 1);
        auto getAns = [&](int l, int r)
        {
            vector<int> cnt(n + 1);
            vector<int> ans;
            int tot = 0;
            for (int i = l; i <= r; ++i)
            {
                if (cnt[A[i]])
                {
                    ans.push_back(A[i]);
                    ans.push_back(A[i]);
                    cnt[A[i]] = -1;
                    tot += 2;
                    if (tot == k + k)
                        return ans;
                }
                else cnt[A[i]] = i;
            }
            for (int i = l; i <= r; ++i)
                // ans.push_back(A[i]);
            {
                if (extra[A[i]])
                    ++tot, ans.push_back(A[i]);
            }
            if (tot == k + k)
                return ans;
            for (int i = l; i <= r; ++i)
                // ans.push_back(A[i]);
            {
                if (~cnt[A[i]])
                {
                    ans.push_back(A[i]);
                    extra[A[i]] = 1;
                    if (++tot == k + k)
                        return ans;
                }
            }
        };
        auto L = getAns(1, n), R = getAns(n + 1, m);
        for (int i = 0; i < L.size(); ++i)
            cout << L[i] << " \n"[i == L.size() - 1];

        for (int i = 0; i < R.size(); ++i)
            cout << R[i] << " \n"[i == R.size() - 1];
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
