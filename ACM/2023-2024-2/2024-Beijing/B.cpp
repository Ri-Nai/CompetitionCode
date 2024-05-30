#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
    int T = rd();
    vector<array<int, 5>> Q;
    vector<int> ans(T);
    for (int i = 0; i < T; ++i)
    {
        int l = rd(), r = rd(), n = rd(), m = rd();
        if (m > 20)
            m = 20;
        Q.push_back({l, r, n, m, i});
    }
    auto cmp = [&](auto x, auto y)
    {
        return x[3] < y[3];
    };
    sort(Q.begin(), Q.end(), cmp);
    int m0 = 1;
    vector<int> nums;
    auto Ins = [&](int m)
    {
        // printf("%d\n", m);
        ll now = 1;
        vector<int> tmp;
        for (int i = m; ; ++i)
        {
            if (now > 1e9)
                break ;
            tmp.push_back(now);
            now = now * (i + 1) / (i - m + 1);
        }
        auto Merge = [&] (vector<int> A, vector<int> B)
        {
            int l1 = A.size(), l2 = B.size();
            vector<int> T;
            for (int i = 0, j = 0; i < l1 || j < l2;)
            {
                if (i == l1 || j < l2 && B[j] < A[i])
                    T.push_back(B[j++]);
                else T.push_back(A[i++]);
            }
            return T;
        };
        nums = Merge(nums, tmp);
        // for (auto x : nums)
            // printf("%d ", x);
        // puts("12");
        auto it = unique(nums.begin(), nums.end());
        // for (auto x : nums)
            // printf("%d ", x);
        // puts("23");
        nums.erase(it, nums.end());
    };
    auto Solve = [&](int p)
    {
        auto [l, r, n, m, id] = Q[p];
        while (m0 < m)
            Ins(++m0);
        auto Get = [&](int x)
        {
            if (n >= x)
                return x;
            auto lp = upper_bound(nums.begin(), nums.end(), n);
            auto rp = upper_bound(nums.begin(), nums.end(), x);
            return n + (rp - lp);
        };
        ans[id] = Get(r) - Get(l - 1);
    };
    for (int i = 0; i < T; ++i)
        Solve(i);
    for (int i = 0; i < T; ++i)
        printf("%d\n", ans[i]);
}
