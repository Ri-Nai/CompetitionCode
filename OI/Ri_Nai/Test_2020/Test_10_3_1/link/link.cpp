#include<bits/stdc++.h>
using namespace std;
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define FCLS() fclose(stdin);fclose(stdout);
#define ToMax(x,y) (x<(y))&&(x=(y))
const int N=2e5+5,M=N<<1,mod=10007;
int n,W[N],sum,mx,sz[N],Mx[N];
int nxt[M],to[M],head[N],tot;
void AMD(int &x,int y)
{
	(x+=y)>=mod&&(x-=mod);
}
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
void dfs(int u,int f)
{
	for(int i=head[u],v;v=to[i];i=nxt[i])
	{
		if(v==f)continue;
		dfs(v,u);//sz是加过的,可能会爆
		AMD(sum,1ll*sz[v]*W[u]%mod);
		AMD(sum,1ll*sz[u]*W[v]%mod);
		AMD(sz[u],W[v]);
		ToMax(mx,Mx[v]*W[u]);
		ToMax(mx,Mx[u]*W[v]);
		ToMax(Mx[u],W[v]);
	}
}
int main()
{
	// FILE("link");
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		Add(u,v),Add(v,u);
	for(int i=1;i<=n;++i)
		scanf("%d",&W[i]);
	dfs(1,0);AMD(sum,sum);
	printf("%d %d\n",mx,sum);
	FCLS();
}
/*
4
1 3
2 4
1 2
3 7 8 9
*/