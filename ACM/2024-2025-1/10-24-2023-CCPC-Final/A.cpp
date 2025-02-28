#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int A[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n + n; ++i)
        scanf("%d", &A[i]);
    sort(A + 1, A + n + n + 1);
    int total = 0;
    for (int i = 2; i <= n + n; ++i)
        total += A[i] == A[i - 1];
    if (total >= n)
        puts("Qingyu");
    else
        puts("Kevin");
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
