#include<bits/stdc++.h>
using namespace std;
typedef multiset<int>::iterator mt;
const int N=2e5+5;
multiset<int>S[N];
int nxt[N],to[N],head[N],tot,A[N];
inline void Add(int u,int v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void Merge(int u,int v)
{
	if(S[u].size()<S[v].size())swap(S[u],S[v]);
	for(mt it=S[v].begin();it!=S[v].end();++it)
		S[u].insert(*it);
}
void dfs(int u)
{
	for(int i=head[u],v;(v=to[i]);i=nxt[i])
		dfs(v),Merge(u,v);
	mt it=S[u].lower_bound(A[u]);
	if(it!=S[u].end())S[u].erase(it);
	S[u].insert(A[u]);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1,u;i<=n;++i)
		scanf("%d%d",&A[i],&u),Add(u,i);
	dfs(1);printf("%d\n",S[1].size());
}