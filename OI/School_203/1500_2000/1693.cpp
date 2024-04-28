#include<bits/stdc++.h>
using namespace std;
const int N=505;
bool E[N][N],vis[N],vsx[N],vsy[N];
int MC[N],n,ctx,cty;
inline void Add(int u,int v)
{
	if(!vsx[u])vsx[u]=++ctx;
	if(!vsy[v])vsy[v]=++cty;
	E[u][v]=1;
}
bool dfs(int u)
{
	for(int v=1;v<=500;++v)
		if(E[u][v]&&!vis[v]&&(vis[v]=1)&&(!MC[v]||dfs(MC[v])))
			return MC[v]=u;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),Add(u,v);
	if(ctx!=cty)return puts("Mirko"),0;
	for(int i=1;i<=500;++i)if(vsx[i])
	{
		memset(vis,0,sizeof vis);
		if(!dfs(i))return puts("Mirko"),0;
	}
	puts("Slavko");
}