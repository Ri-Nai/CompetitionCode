#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,fa[N],fly[N];
int find(int u)
{
	if(u==fa[u])return fa[u];
	int fu=find(fa[u]);
	(fly[u]+=fly[fa[u]])&=1;
	return fa[u]=fu;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,fly[i]=0;
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu!=fv)fa[fu]=fv,fly[fu]=(-fly[u]+fly[v]+1)&1;
		else if(fly[u]==fly[v])return printf("%d\n",i),0;
	}
}