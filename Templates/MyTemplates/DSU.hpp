#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    int n;
    vector<int> fa;
    DSU(int len) : n(len), fa(n + 1) { iota(fa.begin(), fa.end(), 0); }
    int find(int u)
    {
        while (u ^ fa[u])
            u = fa[u] = fa[fa[u]];
        return u;
    }
    void Merge(int u, int v)
    {
        u = find(u), v = find(v);
        fa[v] = u;
    }
};

struct DSU_
{
    int n;
    vector<int> fa, sz, tag;
    stack<int> stk;
    DSU_(int size) : n(size), fa(n + 1), sz(n + 1, 1), tag(n + 1)
    {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int u)
    {
        while (u ^ fa[u])
            u = fa[u];
        return u;
    }
    void Merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v)
            return;
        if (sz[u] < sz[v])
            swap(u, v);
        fa[v] = u;
        tag[v] -= tag[u];
        sz[u] += sz[v];
        stk.push(v);
    }
    void roll_back(int state)
    {
        while (stk.size() != state)
        {
            int v = stk.top();
            stk.pop();
            int u = fa[v];
            fa[v] = v;
            tag[v] += tag[u];
            sz[u] -= sz[v];
        }
    }
    int get_state() { return stk.size(); }
    void Update(int x) { tag[find(1)] += x; }
};
