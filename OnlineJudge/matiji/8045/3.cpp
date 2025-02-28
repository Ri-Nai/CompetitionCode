#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct Mat
    {
        vector<vector<int>> data;
        int n;
        Mat(int n, int k)
            : n(n), data(n, vector<int>(3))
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    data[i][j] = i == j ? k : 0;
        }
        Mat operator*(const Mat &_) const
        {
            Mat res(n, 0);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k)
                        res.data[i][j] ^= data[i][k] & _.data[k][j];
            return res;
        }
        Mat pow(int x)
        {
            Mat res(n, 1);
            Mat p = *this;
            while (x)
            {
                if (x & 1)
                    res = res * p;
                p = p * p;
                x >>= 1;
            }
            return res;
        }
    };
    int n;
    cin >> n;
    Mat initial(3, 0), trans(3, 0);
    initial.data = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
    };
    trans.data = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
    };
    
    auto res = trans.pow(n) * initial;
    for (int i = 0; i < 3; ++i)
        cout << (res.data[i][0] ? "odd" : "even") << endl;
}
