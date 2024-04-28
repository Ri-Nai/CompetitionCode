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
        int n = rd();
        vector<int> A;
        for (int i = 0; i < n; ++i)
            A.push_back(rd());
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        n = A.size();
        int last = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (!last)
                last = 1;
            else
                last = A[i + 1] - A[i] != 1;
        }
        if (A[0] == 1)
        {
            if (!last)
                puts("Alice");
            else
                puts("Bob");
        }
        else
            puts("Alice");
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
