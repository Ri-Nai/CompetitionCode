#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> cnt(26);
    string s;
    cin >> s;
    for (auto c : s)
        ++cnt[c - 'a'];
    cout << s.size() - *max_element(cnt.begin(), cnt.end()) << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
