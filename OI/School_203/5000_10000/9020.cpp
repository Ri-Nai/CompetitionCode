#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define drep(a, b, c) for (int a = b; a >= c; --a)
#define erep(a, b) for (int a = 0; a < E[b].size(); ++a)
#define M 10005
 
const double Exp = 1e-9;
 
int Case;
 
int T, n;
 
vector<int> E[M];
 
double k[M], e[M], onexs[M], faxs[M], cons[M], xs[M];
double ans;
 
bool mark[M];
 
void dfs (int u, int fa) {
    cons[u] = 1 - k[u] - e[u];
    onexs[u] = k[u];
    faxs[u] = (1 - k[u] - e[u]) / E[u].size();
    xs[u] = 1;
    erep(i, u) {
        int& v = E[u][i];
        if (v == fa) continue;
        dfs(v, u);
        onexs[u] += (1 - k[u] - e[u]) * onexs[v] / E[u].size();
        cons[u] += (1 - k[u] - e[u]) * cons[v] / E[u].size();
        xs[u] -= (1 - k[u] - e[u]) * faxs[v] / E[u].size();
    }
    if (u == 1) ans = -1;
    if (u == 1) {
        xs[u] -= onexs[u];
        if (abs(xs[u]) <= Exp) return;
        ans = cons[u] / xs[u];
        return;
    }
    onexs[u] /= xs[u];
    faxs[u] /= xs[u];
    cons[u] /= xs[u];
}
 
int main () {
    scanf ("%d", &T);
 
    while (T--) {
        scanf ("%d", &n);
 
        rep(i, 1, n - 1) {
            int u, v;
            scanf ("%d%d", &u, &v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
 
        rep(i, 1, n) {
            int a, b;
            scanf ("%d%d", &a, &b);
            k[i] = a / 100.0;
            e[i] = b / 100.0;
        }
 
        dfs(1, 0);
 
        if (ans < 0) printf ("Case %d: impossible\n", ++Case);
        else printf ("Case %d: %f\n", ++Case, ans);
 
        rep(i, 1, n) E[i].clear();
    }
 
    return 0;
}