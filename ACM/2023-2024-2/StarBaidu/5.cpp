#include <bits/stdc++.h>
using namespace std;
int rd()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
        c == '-' && (f = -1), c = getchar();
    while (isdigit(c))
        res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res * f;
}
void Solve()
{
    int n = rd();
    vector<int> A;
    if (n == 1)
    {
        cout << 0 << '\n';
        return ;
    }
    for (int i = 1; i <= n; ++i)
        A.push_back(rd());
    sort(A.begin(), A.end());
    vector<int> B, C;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (A[i] < 0)
            B.push_back(-A[i]);
        else if (A[i] > 0)
            C.push_back(A[i]);
        else ++cnt;
    if (B.empty() && C.empty())
    {
        cout << 0 << '\n';
        return ;
    }
    reverse(B.begin(), B.end());
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i < B.size(); ++i)
        ans1 += B[i], ans1 += (B.size() > 1 && i == B.size() - 1) ? B[i] : 0;
    for (int i = 0; i < C.size(); ++i)
        ans2 += C[i], ans2 += (C.size() > 1 && i == C.size() - 1) ? C[i] : 0;
    if (!cnt && (B.empty() || C.empty()))
    {
        auto V = B.empty() ? C : B;
        long long res = 0;
        if (V.size() == 2)
        {
            cout << V[1] << '\n';
            return ;
        }
        for (int i = 1; i < V.size(); ++i)
            res += V[i], res += (i == V.size() - 1) ? V[i] : 0;
        res -= V[0];
        cout << res << '\n';
        return ;
    }
    cout << ans1 + ans2 << '\n';
}
int main()
{
    int T = rd();
    while (T--)
        Solve();
}
