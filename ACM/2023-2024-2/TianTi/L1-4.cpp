#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(m + 1);
    int limit = n;
    int sum = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> A[i];
        sum += A[i];
        limit = min(limit, A[i]);
    }
    for (int i = limit; i >= 0; --i)
    {
        if ((n - i) * (m - 1) + i * m < sum)
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout<<0<<'\n';
}
