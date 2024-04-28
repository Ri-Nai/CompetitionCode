#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,A[N],mn=2e9;
int head[N],to[N<<1],nxt[N<<1],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
int gcd(int u,int v)
{
	return v?gcd(v,u%v):u;
}
struct LQR
{
	int sum,num;
	LQR(){sum=num=114514;}
	LQR(int _,int __){sum=_,num=__;}
	bool operator <(const LQR &_)const
	{
		return sum*_.num<_.sum*num;
	}
	LQR operator +(const LQR &_)const
	{
		return LQR(sum*_.sum,num+_.num);
	}
	LQR operator +(const int &_)const
	{
		return LQR(sum*_,num+1);
	}
}f[N],g[N],ans;
void dfs(int u,int fa)
{
	f[u]=g[u]=LQR(A[u],1);
	for(int i=head[u],v;(v=to[i]);i=nxt[i])
	{
		if(v==fa)continue;dfs(v,u);
		if(A[u]==1)
		{
			ans=min(ans,min(f[u],g[u])+f[v]);
            ans=min(ans,min(f[v],g[v])+f[u]);
            f[u]=min(f[u],f[v]+1);
            g[u]=min(g[u],g[v]+1);
		}
		else if(A[u]==2)
		{
			ans=min(ans,g[u]+f[v]);
            g[u]=min(g[u],f[v]+2);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),mn=min(mn,A[i]);
	if(mn>1)printf("%d/1\n",mn),exit(0);
	dfs(1,0);int gd=gcd(ans.sum,ans.num);
	printf("%d/%d\n",ans.sum/gd,ans.num/gd);
}