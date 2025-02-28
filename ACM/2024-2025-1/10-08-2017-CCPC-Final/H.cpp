#include <bits/stdc++.h>
using namespace std;
int main()
{
    auto solve = [&]()
    {
        auto check0 = [](double x)
        {
            return fabs(x) < 1e-10;
        };
        auto show = [&](auto res)
        {
            for (int i = 0; i < res.size(); ++i)
                printf("%.10lf%c", res[i], " \n"[i == res.size() - 1]);
        };
        int n, m;
        scanf("%d%d", &n, &m);
        cout << n - m + 1 << '\n';
        vector<vector<double>> vecs(m, vector<double>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%lf", &vecs[i][j]);
        auto get_normal = [&]()
        {
            vector<vector<double>> mat;
            for (int i = 1; i < m; ++i)
            {
                auto res = vecs[0];
                auto vec = vecs[i];
                for (int j = 0; j < n; ++j)
                    res[j] -= vec[j];
                mat.push_back(res);
            }
            vector<double> ans(n);
            int rows = mat.size();
            int cols = n;
            if (!rows)
            {
                ans[0] += 1;
                for (int i = 0; i < n; ++i)
                    ans[i] += vecs[0][i];
            }
            else
            {
                auto clear = [&](int col0, int by, int from, int to)
                {
                    for (int row = from; row < to; ++row)
                    {
                        if (check0(mat[row][col0]))
                            continue;
                        double times = mat[row][col0] / mat[by][col0];
                        for (int col = 0; col < cols; ++col)
                            mat[row][col] = mat[row][col] - times * mat[by][col];
                    }
                };
                vector<int> Main, Free;
                // cout << rows << ' ' << cols << '\n';
                for (int row = 0, col = 0; col < cols; ++row, ++col)
                {
                    if (row >= rows)
                    {
                        Free.push_back(col);
                        continue;
                    }
                    int num = row;
                    for (int nxt = row + 1; nxt < rows; ++nxt)
                        if (check0(mat[num][col]) || fabs(mat[num][col]) < fabs(mat[nxt][col]))
                            num = nxt;
                    if (check0(mat[num][col]))
                    {
                        Free.push_back(col);
                        --row;
                    }
                    else
                    {
                        Main.push_back(col);
                        swap(mat[row], mat[num]);
                        clear(col, row, row + 1, rows);
                    }
                }
                int rank = Main.size();
                for (int row = rank - 1; row >= 0; --row)
                    clear(Main[row], row, 0, row);
                for (auto freeCol : Free)
                {
                    ans[freeCol] += 1;
                    for (int row = 0; row < Main.size(); ++row)
                    {
                        int mainCol = Main[row];
                        ans[mainCol] += -mat[row][freeCol] / mat[row][mainCol];
                    }
                }
            }
            // cout << '\n';
            double totalLength = 0;
            for (int i = 0; i < n; ++i)
                totalLength += ans[i] * ans[i];
            totalLength = sqrt(totalLength);
            for (int i = 0; i < n; ++i)
                ans[i] /= totalLength;
            // cout << totalLength << '\n';
            return ans;
        };
        auto get_middle = [&]()
        {
            vector<double> ans(n);
            for (auto vec : vecs)
                for (int i = 0; i < vec.size(); ++i)
                    ans[i] += vec[i];
            for (int i = 0; i < ans.size(); ++i)
                ans[i] /= vecs.size();
            return ans;
        };
        auto get_dis = [&](auto vec1, auto vec2)
        {
            double ans = 0;
            for (int i = 0; i < vec1.size(); ++i)
                ans += (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]);
            return ans;
        };
        for (; m <= n; ++m)
        {
            auto normal = get_normal();
            auto middle = get_middle();
            auto dis = get_dis(vecs[0], middle);
            auto diff = sqrt(1 - dis);
            vector<double> res(n);
            for (int i = 0; i < middle.size(); ++i)
                res[i] = middle[i] + diff * normal[i];
            show(res);
            for (auto vec : vecs)
                assert(check0(get_dis(vec, res) - 1));
            vecs.push_back(res);
        }
    };
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d: ", i);
        solve();
    }
}
/*
1
20 1
1.0000000000 2.0000000000 0 0 0 1.0000000000 0.0000000000 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
