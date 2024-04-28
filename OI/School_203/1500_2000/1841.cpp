#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,fa[N],f[N][N];
int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(!m&&n!=2)return !puts("NE");
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),f[u][v]=f[v][u]=1,fa[find(u)]=find(v);
	for(int u=1;u<=n;++u)
		for(int v=1;v<=n;++v)
			if(u!=v&&find(u)==find(v)&&!f[u][v])
				return !puts("NE");
	puts("DA");
}