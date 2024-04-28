#include<bits/stdc++.h>
using namespace std;
#define EOR(i,u) for(int i=head[u],v;v=to[i];i=nxt[i])
typedef long long LL;
struct Pr
{
	LL first;int second;
	bool operator <(const Pr &_)const
	{
		return first<_.first;
	}
};
const int N=5e4+5,M=N<<1;
int n,m,A[N],fa[N][16],cnt,num,Rst[N];
int nxt[M],to[M],W[M],head[N],tot;
LL dis[N][16],C[N];
bool mark[N],is[N];
Pr B[N];
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
void dfs(int u,int f)
{
	for(int i=1; i<16; ++i)
		fa[u][i]=fa[fa[u][i-1]][i-1],dis[u][i]=dis[u][i-1]+dis[fa[u][i-1]][i-1];
	EOR(i,u)if(v^f)
		dis[v][0]=W[i],dfs(v,fa[v][0]=u);
}
bool chk(int u,int f)
{
	if(mark[u])return 1;
	if(!nxt[head[u]])return 0;
	EOR(i,u)if(v!=f)
		if(!chk(v,u))return 0;
	return 1;
}
bool check(LL mid)
{
	num=cnt=0;
	for(int i=1; i<=n; ++i)is[i]=mark[i]=0;
	for(int i=1; i<=m; ++i)
	{
		int u=A[i];
		LL now=0;
		for(int j=15; ~j; --j)
			if(fa[u][j]!=1&&dis[u][j]+now<=mid)
				now+=dis[u][j],u=fa[u][j];
		if(fa[u][0]==1&&now+dis[u][0]<=mid)
			B[++cnt]=(Pr){mid-dis[u][0]-now,u};
		else mark[u]=1;
	}
	EOR(i,1)if(!chk(v,1))is[v]=1;
	sort(B+1,B+cnt+1);//为什么总有nt想要用堆 
	for(int i=1; i<=cnt; ++i)
	{
		int now=B[i].second;
		if(is[now]&&B[i].first<=dis[now][0])is[now]=0;//转到这个地方
		else C[++num]=B[i].first;//匹配其他的点
	}
	sort(C+1,C+num+1);
	cnt=0;
	EOR(i,1)if(is[v])Rst[++cnt]=W[i];
	if(cnt==0)return 1;
	if(num<cnt)return 0;
	sort(Rst+1,Rst+cnt+1);
	int now=1;
	for(int i=1; i<=num; ++i)
		if(now<=cnt&&C[i]>=Rst[now])++now;
	return now==cnt+1;
}
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	do t=(t<<1)+(t<<3)+(c^48);while(isdigit(c=getchar()));
	return f?-t:t;
}
int main()
{
	n=rd();
	for(int i=1,u,v,w; i<n; ++i)
		u=rd(),v=rd(),w=rd(),Add(u,v,w),Add(v,u,w);
	m=rd();
	fa[1][0]=1;dfs(1,1);
	for(int i=1; i<=m; ++i)A[i]=rd();
	LL L=1,R=5e13,ans=-1;
	while(L<=R)
	{
		LL mid=L+R>>1;
		if(check(mid))
			ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",ans);
}
