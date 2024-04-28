#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
LL C1[N],C2[N];
int n,m,L[N],R[N],num;
int nxt[N<<1],head[N],to[N<<1],tot;
inline void Adde(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v,head[u]=tot;
}
void dfs(int u,int f)
{
	L[u]=++num;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)dfs(to[i],u);
	R[u]=num;
}
void Add(int x,int y)
{
	for(int i=x;i<=n;i+=i&-i)
		C1[i]+=y,C2[i]+=1ll*y*(x-1);
}
LL Sum(int x)
{
	LL res=0;
	for(int i=x;i;i^=i&-i)
		res+=1ll*x*C1[i]-C2[i];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		Adde(u,v),Adde(v,u);
	dfs(1,0);
	for(int u,op,w;m--;)
	{
		scanf("%d%d",&op,&u);
		if(op==2)printf("%lld\n",Sum(R[u])-Sum(L[u]-1));
		else scanf("%d",&w),Add(L[u],w),Add(R[u]+1,-w);
	}
}