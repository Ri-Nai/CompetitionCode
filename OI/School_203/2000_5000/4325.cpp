#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=35,mod=1e4+7;
int head[N],to[N<<1],nxt[N<<1],tot;
int n,m,Q,fa[20][N],dep[N],L[M],R[M],Rt[N][M][M];
char s[N],q[M];
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void Mod(int &x,int y)
{
	y>mod&&(y-=mod);
	y<0&&(y+=mod);
	x+=y;
	x>mod&&(x-=mod);
	x<0&&(x+=mod);
}
void dfs(int u,int f)
{
	fa[0][u]=f;dep[u]=dep[f]+1;
	memcpy(Rt[u],Rt[f],sizeof Rt[u]);
	for(int i=1;i<=m;++i)
	{
		if(s[u]==q[i])continue;Mod(Rt[u][i][i],1);
		for(int j=i-1;j>0;--j)Mod(Rt[u][i][j],Rt[f][i][j-1]);
		for(int j=i+1;j<m;++j)Mod(Rt[u][i][j],Rt[f][i][j+1]);
	}
	for(int i=1;i<=19;++i)fa[i][u]=fa[i][fa[u][i-1]];
	for(int i=head[u];~i;i=nxt[i])if(to[i]^f)dfs(to[i],u);
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	const int &step=dep[u]-dep[v];
	for(int i=0;i<=19;++i)
		if(step&1<<i)u=fa[i][u];
	if(u==v)return u;
	for(int i=19;~i;--i)
		if(fa[i][u]^fa[i][v])
			u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
void Clear()
{
	memset(head,-1,sizeof head);tot=0;
}
int Dp1(int u,int F)
{
	for(int i=1;i<=m;++i)
	{
		L[i]=Rt[u][1][i]-Rt[F][1][i];
		L[i]<0&&(L[i]+=mod);
		for(int j=1;j<=i-1;++j)
			Mod(L[i],-1ll*L[j]*Rt[F][j+1][i]%mod);
	}
	return L[m];
}
int Dp2(int u,int F)
{
	for(int i=m;i>=1;--i)
	{
		R[i]=Rt[u][m][i]-Rt[F][m][i];
		R[i]<0&&(R[i]+=mod);
		for(int j=m;j>=i+1;--j)
			Mod(R[i],-1ll*R[j]*Rt[F][j-1][i]%mod);
	}
	return R[1];
}
long long Query(int u,int v)
{
	if(u==v)return m==1&&s[u]==q[1];
	int lca=LCA(u,v);
	if(lca==v)return Dp1(u,fa[0][v]);
	if(lca==u)return Dp2(v,fa[0][u]);
	int ans=Dp1(u,lca)+Dp2(v,fa[0][lca]);
	for(int i=1;i<m;++i)(ans+=L[i]*R[i+1])%=mod;
	return ans;
}
void solve()
{
	Clear();
	scanf("%d%d",&n,&Q);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		Add(u,v),Add(v,u);
	scanf("%s %s",s+1,q+1);
	m=strlen(q+1);dfs(1,0);
	for(int u,v;Q--;)
		scanf("%d%d",&u,&v),
		printf("+++++++++%lld\n",Query(u,v));
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}