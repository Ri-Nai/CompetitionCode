#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define EOR(i,L,u) \
for(register int i=L.head[u],v,w;w=L.W[i],v=L.to[i];i=L.nxt[i])
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
const int N=5e5+5,M=2e6+5;
int n,m,dfn[N],low[N],mx,blg[N],stk[N],blk,top,num,dp[2][N];
void ToMin(int &x,const int &y){y<x&&(x=y);}
void ToMax(int &x,const int &y){y>x&&(x=y);}
int rd()
{
	int t=0,c;do c=getchar();while(!isdigit(c));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
struct Link
{
	int head[N],to[M],W[M],nxt[M],tot;
	Link(){memset(head,0,sizeof head),tot=0;}
	void Add(int u,int v,int w)
	{
		nxt[++tot]=head[u];
		to[head[u]=tot]=v;
		W[tot]=w;w>mx&&(mx=w);
	}
}A,B;
void Tarjan(int u,int f)
{
	dfn[stk[++top]=u]=low[u]=++num;
	EOR(i,A,u)if(v!=f)
	{
		if(dfn[v])ToMin(low[u],dfn[v]);
		else Tarjan(v,u),ToMin(low[u],low[v]);
	}
	if(low[u]==dfn[u])
	{
		int v;++blk;
		do blg[v=stk[top--]]=blk;while(u!=v);
	}
}
void Fly(int u,int f,int &mx,int &num,const int &t)
{
	dp[0][u]=dp[1][u]=0;
	EOR(i,B,u)if(v!=f)
	{
		Fly(v,u,mx,num,t);
		int now=dp[0][v];
		if(w<=t)++now,++num;
		if(now>dp[0][u])
			std::swap(dp[0][u],dp[1][u]),dp[0][u]=now;
		else if(now>dp[1][u])dp[1][u]=now;
	}
	ToMax(mx,dp[0][u]+dp[1][u]);
}
bool cook(int t)
{
	int mx=0,num=0;
	Fly(1,0,mx,num,t);
	return mx==num;
}
int main()
{
	n=rd();FOR(i,1,rd())
	{
		int u=rd(),v=rd(),w=rd();
		A.Add(u,v,w);A.Add(v,u,w);
	}
	Tarjan(1,0);FOR(u,1,n)EOR(i,A,u)
		if(blg[u]!=blg[v])B.Add(blg[u],blg[v],w);
	int L=1,R=mx,mid,ans=-1;
	while(L<=R)
	{
		mid=L+R>>1;
		if(cook(mid))
			ans=mid+1,L=mid+1;
		else R=mid-1;
	}
	printf("%d\n",ans==mx+1?-1:ans);
}