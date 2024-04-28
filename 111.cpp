#include<bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int m, a[N], t[N][26], f[N], fa[N], tot, cnt, Tot, c[N], dfn[N], fin[N], ans[N];
bool b[N][26];
inline void add(int i, int x)
{
	for(++i; i < N; i += i & -i)
		c[i] += x;
}
inline int sum(int i)
{
	int res = 0;
	for(++i; i; i &= i - 1)
		res += c[i];
	return res;
}
vector<int> e[N];
vector<pair<int, int>> qs[N];
void dfs1(int u)
{
	dfn[u] = ++Tot;
	for(int v : e[u])
		dfs1(v);
	fin[u] = Tot;
}
void dfs2(int u)
{//if(u==a[8])cout<<sum(dfn[u]) - sum(dfn[u] - 1);
	add(dfn[u], 1);//if(u==a[8])cout<<sum(dfn[u]) - sum(dfn[u] - 1);
	if(!qs[u].empty())
	{
		for(auto [x, id] : qs[u])
		{
			ans[id] = sum(fin[x]) - sum(dfn[x] - 1);
		}
	}
	for(int i = 0; i < 26; ++i)
	{
		if(b[u][i])
		{
			dfs2(t[u][i]);
		}
	}
	add(dfn[u], -1);
}
int main()
{
	string s;
	cin >> s;
	int u = 0;
	for(char c : s)
	{
		if(c == 'B')
			u = fa[u];
		else if(c == 'P')
			a[++cnt] = u;
		else
		{
			if(!t[u][c - 'a'])
				fa[t[u][c - 'a'] = ++tot] = u, b[u][c - 'a'] = 1;
			u = t[u][c - 'a'];
		}
	}
	queue<int> q;
	for(int i = 0; i < 26; ++i)
		if(t[0][i])
			q.emplace(t[0][i]);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < 26; ++i)
			(t[u][i] ? (q.emplace(t[u][i]), f[t[u][i]]) : t[u][i]) = t[f[u]][i];
	}
	for(int i = 1; i <= tot; ++i)
		e[f[i]].emplace_back(i);//,cout<<f[i];
	cin >> m;
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		qs[a[y]].emplace_back(a[x], i);
	}
	dfs1(0);
	dfs2(0);
	copy(ans + 1, ans + m + 1, ostream_iterator<int>(cout, "\n"));
	return 0;
}
