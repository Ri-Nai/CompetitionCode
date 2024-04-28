#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> A(9, vector<int>(9));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                cin >> A[i][j];
        int flag = 1;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (A[i][j] <= 0 || A[i][j] > 9)
                {
                    flag = 0;
                    A[i][j] = 0;
                }
        auto checkx = [&](int x)
        {
            vector<int> cnt(10);
            for (int i = 0; i < 9; ++i)
            {
                if (cnt[A[x][i]])
                    return 0;
                cnt[A[x][i]] = 1;
            }
            return 1;
        };
        auto checky = [&](int y)
        {
            vector<int> cnt(10);
            for (int i = 0; i < 9; ++i)
            {
                if (cnt[A[i][y]])
                    return 0;
                cnt[A[i][y]] = 1;
            }
            return 1;
        };
        auto checkgong = [&](int x, int y)
        {
            vector<int> cnt(10);
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (cnt[A[x + i][y + j]])
                        return 0;
                    cnt[A[x + i][y + j]] = 1;
                }
            }
            return 1;
        };
        for (int i = 0; i < 9; ++i)
            flag &= checkx(i) & checky(i);
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
                flag &= checkgong(i, j);
        cout << flag << '\n';
    }
}
