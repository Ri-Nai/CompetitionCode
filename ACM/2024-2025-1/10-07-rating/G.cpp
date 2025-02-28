#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int ans = 0;
        ans += x / 3;
        x %= 3;
        while (x && y >= 2)
            --x, y -= 2, ++ans;
        while (x && z >= 2)
            --x, z -= 2, ++ans;
        ans += (y + z) / 3;
        cout << ans << '\n';
    }
}
