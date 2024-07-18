#include <bits/stdc++.h>
using namespace std;
void file()
{
    freopen("J.in", "r", stdin);
    freopen("J.out", "w", stdout);
}
const int N = 1e5 + 10, M = 510;
struct Solve
{
    int siz, a[N], len, tot, top[M], n, ans1[M][M];
    long long b[M][M], ans2[M][M];
    int strt[M], ed[M];
    void getans(int pos, int l, int r, int &ans1, long long &ans2)
    {
        ans1 = ans2 = 0;
        for (int i = l; i <= r; ++i)
        {
            if (pos + a[i] > siz)
                ans2 += siz - pos, pos = siz;
            else if (pos + a[i] < 0)
                ans2 += pos, pos = 0;
            else
                ans2 += max(a[i], -a[i]), pos += a[i];
        }
        ans1 = pos;
    }
    void init()
    {
        len = sqrt(n);
        tot = 0;
        for (int i = 1; i <= n; i += len)
            strt[++tot] = i, ed[tot] = min(n, i + len - 1);
        for (int i = 1; i <= tot; ++i)
        {
            long long l = 0, r = siz;
            b[i][++top[i]] = l, b[i][++top[i]] = r;
            long long nowpos = 0;
            for (int j = strt[i]; j <= ed[i]; ++j)
            {
                nowpos += a[j];
                if (nowpos > 0)
                {
                    r = min(r, siz - nowpos);
                    if (r >= l)
                        b[i][++top[i]] = r;
                }
                else if (nowpos < 0)
                {
                    l = max(l, -nowpos);
                    if (l <= r)
                        b[i][++top[i]] = l;
                }
                if (l >= r)
                    break;
            }
            sort(b[i] + 1, b[i] + 1 + top[i]);
            top[i] = unique(b[i] + 1, b[i] + 1 + top[i]) - b[i] - 1;
            for (int j = 1; j <= top[i]; ++j)
                getans(b[i][j], strt[i], ed[i], ans1[i][j], ans2[i][j]);
            //          for(int j = 1; j <= top[i]; ++j) cout << b[i][j] << " "; cout << endl;
        }
        //      for(int i = 1; i <= tot; ++i) cout << strt[i] << " " << ed[i] << endl;
        //      cout << endl;
    }
    void getans2(int pos, int id, int &p, long long &length)
    {
        length = 0;
        int tp = lower_bound(b[id] + 1, b[id] + top[id] + 1, pos) - b[id];
        //      cout << id << " " << top[id] << endl;
        //      for(int i = 1; i <= top[id]; ++i) cout << b[id][i] << " "; cout << endl;
        if (tp == 1)
        {
            p = ans1[id][tp], length = ans2[id][tp];
            return;
        }
        else
        {
            p = ans1[id][tp - 1] + (ans1[id][tp] - ans1[id][tp - 1]) / (b[id][tp] - b[id][tp - 1]) * (pos - b[id][tp - 1]);
            length = ans2[id][tp - 1] + (ans2[id][tp] - ans2[id][tp - 1]) / (b[id][tp] - b[id][tp - 1]) * (pos - b[id][tp - 1]);
            return;
        }
    }
    void get_ans(int pos, int l, int r, int &p, long long &length)
    {
        length = 0;
        long long tlen;
        getans(pos, l, min(r, (l - 1) / len * len + len), pos, tlen);
        //      cout << pos << " " << tlen << endl;
        length += tlen;
        l = min(r, (l - 1) / len * len + len) + 1;
        if (l > r)
        {
            p = pos;
            return;
        }
        for (int i = (l - 1) / len + 1; i <= tot && ed[i] <= r; ++i)
        {
            getans2(pos, i, pos, tlen);
            length += tlen;
            //          cout << pos << " " << tlen << endl;
            l = ed[i] + 1;
        }
        getans(pos, l, r, p, tlen);
        //      cout << pos << " " << tlen << endl;
        //      cout << endl;
        length += tlen;
    }
} s1, s2;
int q;
char s[10];
int main()
{
    //  file();
    ios::sync_with_stdio(0);
    cin >> s1.siz >> s2.siz >> s1.n >> q;
    s2.n = s1.n;
    for (int i = 1; i <= s1.n; ++i)
    {
        int len;
        cin >> s[1];
        cin >> len;
        if (s[1] == 'L')
            s1.a[i] = -len;
        else if (s[1] == 'R')
            s1.a[i] = len;
        else if (s[1] == 'U')
            s2.a[i] = len;
        else
            s2.a[i] = -len;
    }
    s1.init(), s2.init();
    while (q--)
    {
        int x, y, l, r;
        long long ans1, ans2;
        cin >> x >> y >> l >> r;
        s1.get_ans(x, l, r, x, ans1);
        s2.get_ans(y, l, r, y, ans2);
        //      cout << ans1 << " " << ans2 << endl;
        cout << x << " " << y << " " << ans1 + ans2 << endl;
    }
    return 0;
}
