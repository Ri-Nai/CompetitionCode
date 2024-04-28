#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector<string> check(n);
    for (int i = 0; i < n; ++i)
        cin >> check[i];
    cin >> m;
    string s;
    getchar();
    getline(cin, s);
    vector<int> mark(s.size());
    vector<bool> ifmarked(s.size());
    int cnt = 0;
    for (auto x : check)
    {
        for (int i = 0; i < s.size() - x.size() + 1; ++i)
        {
            bool flag = 1;
            for (int j = 0; j < x.size(); ++j)
            {
                if (mark[i + j] || s[i + j] != x[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                ++cnt;
                for (int j = 0; j < x.size(); ++j)
                    mark[i + j] = cnt;
            }
        }
    }
    if (cnt >= m)
    {
        cout<< m << "\nHe Xie Ni Quan Jia!\n";
    }
    else
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (!mark[i])
                cout << s[i];
            else if (!ifmarked[mark[i]])
            {
                ifmarked[mark[i]] = 1;
                cout << "<censored>";
            }
        }
        cout << '\n';
    }
}
