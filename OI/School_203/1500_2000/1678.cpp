#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"inline","Ofast")
#define Rg register
using namespace std;
const int inf=0x3f3f3f3f,N=505,M=10005;
int head[N],to[M],W[M],nxt[M],tot;
int n,m,dis[N][N];
bool vis[N][N];
struct nt
{
	int u,k,b;
	bool operator < (const nt &_)const
	{
		return b==_.b?k>_.k:b>_.b;
	}
};
int rd()
{
	int t=0,c;
	do{c=getchar();if(c=='x')return 0;}while(!isdigit(c));
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
inline void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
void Dijkstra(int s)
{
	for(int i=1;i<=n;++i)
		for(int j=0;j<n;++j)
			dis[i][j]=inf,vis[i][j]=0;
	priority_queue<nt>Q;
	Q.push((nt){s,0,dis[s][0]=0});
	while(!Q.empty())
	{
		nt p=Q.top();Q.pop();
		int u=p.u,k=p.k,b=p.b;
		if(k>=n)continue;
		if(vis[u][k])continue;
		vis[u][k]=1;
		for(Rg int i=head[u];i;i=nxt[i])
		{
			int &v=to[i],&w=W[i],t=!w;
			if(dis[v][k+t]>b+w)
				dis[v][k+t]=b+w,Q.push((nt){v,k+t,b+w});
		}
	}
}
void solve(int t)
{
	if(!vis[t][0])
	{
		for(Rg int i=1;i<n;++i)
			if(vis[t][i])return (void)puts("inf");
		return (void)puts("0 0");
	}
	long long res=1,num=dis[t][0];
	for(Rg int i=1;i<n;++i)
	{
		if(!vis[t][i])continue;
		int l=1,r=5e8;
		for(Rg int j=0;j<i;++j)
			if(vis[t][j])r=min(r,(dis[t][j]-dis[t][i]-1)/(i-j));
		for(Rg int j=i+1;j<n;++j)
			if(vis[t][j])l=max(l,(dis[t][i]-dis[t][j]-1)/(j-i)+1);
		if(l>r)continue;
		res+=r-l+1,num+=1ll*(r-l+1)*dis[t][i]+1ll*(r+l)*(r-l+1)/2*i;
	}
	printf("%lld %lld\n",res,num);
}
int main()
{
	n=rd();m=rd();
	for(Rg int i=1,u,v,w;i<=m;++i)u=rd(),v=rd(),w=rd(),Add(u,v,w);
	for(Rg int u,v,Q=rd();Q--;)u=rd(),v=rd(),Dijkstra(u),solve(v);
}