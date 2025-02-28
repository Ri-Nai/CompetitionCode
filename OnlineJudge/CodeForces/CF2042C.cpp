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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> sum(n + 1);
        priority_queue<int> Q;
        for (int i = n - 1; i > 0; --i)
        {
            sum[i] = sum[i + 1];
            if (s[i] == '1')
                ++sum[i];
            else 
                --sum[i];
            Q.push(sum[i]);
        }
        long long res = 0;
        for (int i = 1; i <= n - 1; ++i)
        {
            res += Q.top();
            Q.pop();
            if (res >= k)
                End(i + 1);
        }
        End(-1);
    }
}
bool Ri;
int main()
{
    // cout << (&Ri - &Nai) / 8.0 / 1024 / 1024 << '\n';
    ios::sync_with_stdio(0);
    int t; cin >> t; while(t--)
    T::solve();
}
