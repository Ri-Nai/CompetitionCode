#include <vector>
typedef long long ll;
using namespace std;
auto Pre(int n)
{
    vector<int> Pr;
    vector<int> P(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (!P[i])
            P[i] = i - 1, Pr.push_back(i);
        for (auto j : Pr)
        {
            ll now = 1ll * j * i;
            if (now > n)break;
            if (i % j == 0)
            {
                P[now] = j * P[i];
                break;
            }
            P[now] = P[i] * P[j];
        }
    }
}
