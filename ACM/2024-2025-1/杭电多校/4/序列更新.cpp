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
        srand(time(0));
        int n = rd(), q = rd();
        vector<int> A(n + 1), B(n + 1);
        vector<int> L(n + 2), R(n + 2);
        iota(L.begin(), L.end(), -1);
        iota(R.begin(), R.end(), 1);
        auto del = [&](int p)
        {
            R[L[p]] = R[p];
            L[R[p]] = L[p];
        };
        ll sum = 0;
        ll tot = 0, lognum = 0;
        vector<int> nums;
        for (int i = 1; i <= n; ++i)
            A[i] = rd(), sum += A[i];
        for (int i = 1; i <= n; ++i)
        {
            B[i] = rd();
            nums.push_back(A[i]);
            nums.push_back(B[i]);
        }
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        auto C = A, D = B;
        for (int i = 1; i <= n; ++i)
        {
            C[i] = lower_bound(nums.begin(), nums.end(), C[i]) - nums.begin();
            D[i] = lower_bound(nums.begin(), nums.end(), D[i]) - nums.begin();
        }
        int head = 0;
        vector<int> cnts(n + n);
        for (int i = 1; i <= n; ++i)
        {
            if (C[i] < head)
                head = C[i];
            ++cnts[C[i]];
        }
        for (int i = 1; i <= q; ++i)
        {
            int mn = nums[head];
            int k = rd();
            for (int j = R[0]; j != n + 1;)
            {
                ++tot;
                if (B[j] <= mn)
                    del(j);
                else
                {
                    int idx = (j - 1 - k + n) % n + 1;
                    int &now = A[idx];
                    int nxt = B[j];
                    if (nxt > now)
                    {
                        sum += nxt - now;
                        --cnts[C[idx]];
                        ++cnts[D[j]];
                        while (!cnts[head])
                            ++head;
                        C[idx] = D[j];
                        now = nxt;
                    }
                }
                j = R[j];
            }
            cout << sum << '\n';
        }
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    // ios::sync_with_stdio(0);
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t; cin >> t; while(t--)
    T::solve();
}
