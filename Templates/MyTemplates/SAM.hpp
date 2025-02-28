#include <bits/stdc++.h>
using namespace std;
struct SAM
{
    static constexpr int ALPHABET_SIZE = 26;
    struct Node
    {
        int len, link, sz;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, link{}, next{}, sz{} {}
    };
    vector<Node> t;
    vector<int> ord;
    vector<vector<int>> E;
    int n;
    SAM() : n{}
    {
        init();
    }
    SAM(string s)
    {
        init();
        int p = 1;
        for (char c : s)
            p = extend(p, c);
        n = s.size();
    }
    void init()
    {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }

    int extend(int p, int c)
    {
        if (t[p].next[c])
        {
            int q = t[p].next[c];
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = t[q].link;
            t[r].next = t[q].next;
            t[q].link = r;
            while (t[p].next[c] == q)
            {
                t[p].next[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        while (!t[p].next[c])
        {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        t[cur].sz = 1;
        return cur;
    }
    int extend(int p, char c, char offset = 'a')
    {
        return extend(p, c - offset);
    }

    int next(int p, int x)
    {
        return t[p].next[x];
    }

    int next(int p, char c, char offset = 'a')
    {
        return next(p, c - 'a');
    }

    int link(int p)
    {
        return t[p].link;
    }

    int len(int p)
    {
        return t[p].len;
    }

    int size()
    {
        return t.size();
    }

    void move(int &p, int &l, char c)
    {
        while (!next(p, c))
            l = len(p = link(p));
        ++l;
        p = next(p, c);
    }

    void del_head(int &p, int &l, int limit)
    {
        if (l > limit && --l == len(link(p)))
            p = link(p);
    }

    void Build_Ord()
    {
        int m = size();
        vector<int> cnt(n + 1);
        ord.resize(m);
        for (int i = 1; i < m; ++i)
            ++cnt[t[i].len];
        for (int i = 1; i <= n; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = 1; i < m; ++i)
            ord[cnt[t[i].len]--] = i;
        for (int i = m - 1; i >= 1; --i)
        {
            int p = ord[i];
            t[t[p].link].sz += t[p].sz;
        }
    }
    void Build_Edge()
    {
        E.resize(size());
        for (int i = 2; i < size(); ++i)
            E[t[i].link].push_back(i);
    }
};
