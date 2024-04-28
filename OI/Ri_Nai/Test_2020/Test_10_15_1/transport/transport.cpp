#include<bits/stdc++.h>
using namespace std;
#define Rg register
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=3e5+5,M=N<<1;
bool Ri;
struct Que
{
	int u,v,id;
	void read(int i){scanf("%d%d",&u,&v);id=i;}
}Q[N];
int n,m;
int head[N],nxt[M],to[M],W[M],tot;
bool chk()
{
	for(Rg int i=1;i<n;++i)
	{
		int v=max(to[nxt[head[i]]],to[head[i]]);
		if(v!=i+1)return 0;
	}
	return 1;
}
inline void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
namespace P60
{
	const int N=1e5+5;
	int val[N],fa[N][20],dep[N],C[N],L[N],R[N],num,P;
	void Add(int x,int y)
	{
		while(x<=n)C[x]+=y,x+=x&-x;
	}
	int Sum(int x)
	{
		int res=0;
		while(x)res+=C[x],x^=x&-x;
		return res;
	}
	void dfs(int u,int f)
	{
		L[u]=++num;
		for(Rg int i=1;i<=P;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
		for(Rg int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(v==f)continue;
			val[v]=W[i];
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			dfs(v,u);
		}
		R[u]=num;
	}
	void _dfs(int u,int f)
	{
		for(Rg int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(v==f)continue;
			_dfs(v,u);
			Add(L[v],W[i]),Add(R[v]+1,-W[i]);
		}
	}
	int LCA(int u,int v)
	{
		if(dep[u]<dep[v])swap(u,v);
		int step=dep[u]-dep[v];
		for(Rg int i=0;i<=P;++i)
			if(1<<i&step)u=fa[u][i];
		if(u==v)return u;
		for(Rg int i=P;~i;--i)
			if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];
		return fa[u][0];
	}
	void Solve()
	{
		P=log2(n)+2;
		dfs(1,0);_dfs(1,0);
		int ans=1e9+7;
		for(Rg int i=2;i<=n;++i)
		{
			Add(L[i],-val[i]);Add(R[i]+1,val[i]);
			int mx=-1;
			for(Rg int j=1;j<=m;++j)
			{
				int u=Q[j].u,v=Q[j].v,l=LCA(u,v);
				int dis=Sum(L[u])+Sum(L[v])-2*Sum(L[l]);
				if(dis>=ans){mx=-1;break;}
				if(dis>mx)mx=dis;
			}
			if(~mx)ans=mx;
			Add(L[i],val[i]);Add(R[i]+1,-val[i]);
		}
		printf("%d\n",ans);
	}
}
namespace P80
{
	const int N=1e5+5;
	bool cmp(Que A,Que B)
	{
		return A.u==B.u?A.v<B.v:A.u<B.u;
	}
	int Sum[N],tot,dis[N];
	Que B[N];
	multiset<int>In,Out;
	void init()
	{
		for(Rg int i=2;i<=n;++i)
			Sum[i]=Sum[i-1]+W[i-1<<1];
		for(Rg int i=1;i<=m;++i)
			if(Q[i].u>Q[i].v)swap(Q[i].u,Q[i].v);
		sort(Q+1,Q+m+1,cmp);
		for(Rg int i=1,mx=0;i<=m;++i)
		{
			if(Q[i].v<=mx)continue;
			B[++tot]=Q[i];
			Out.insert(dis[tot]=Sum[B[tot].v]-Sum[B[tot].u]);
			mx=Q[i].v;
		}
	}
	void Solve()
	{
		init();
		int l=1,r=1,ans=1e9;
		for(Rg int i=1;i<n;++i)
		{
			while(l<=tot&&Q[l].u<=i)
				Out.erase(dis[l]),In.insert(dis[l]),++l;
			while(r<=tot&&Q[r].v<=i)
				Out.insert(dis[r]),In.erase(dis[r]),++r;
			if(!In.empty()&&!Out.empty())ans=min(ans,max(*Out.rbegin(),*In.rbegin()-W[i<<1])); 
			else if(Out.empty())ans=min(ans,*In.rbegin()-W[i<<1]);
			else ans=min(ans,*Out.rbegin());
		}
		printf("%d\n",ans);
	}
}
bool Nai;
int main()
{
//	printf("%f\n",(&Ri-&Nai)/1024./1024);
	srand(time(0));
//	FILE("transport");
	scanf("%d%d",&n,&m);
	for(Rg int i=1,u,v,w;i<n;++i)
		scanf("%d%d%d",&u,&v,&w),Add(u,v,w),Add(v,u,w);
	for(Rg int i=1;i<=m;++i)Q[i].read(i);
	if(n<=3000||m==1)P60::Solve();
	else if(chk())P80::Solve();
	else printf("%d\n",rand()%(int)3e8);//有分算我输 
	FCLS();
}
/*
6 3
1 2 3
1 6 4
3 1 7
4 3 6
3 5 5
3 6
2 5
4 5

5 3
1 2 12
2 3 4
3 4 10
4 5 6
1 3
2 4
3 5
{
	使这些任务的最大值最小,可能是个二分
	同T2,是一个只能二分答案而不能二分节点或者二分边权的题目 
}
考虑到最终的答案肯定只与经过最大的点的边有关
而其中又与次大,次次大的节点有关

最终答案为max(max(dis_not_in_this_Que),max(dis_in_this_Que)-W[i])
若按照这个贪心思路来想的话,我们要做的有两件事,预处理出从大到小的原始dis
114 51 41 19 9
-------->找出连续的包含这条边的最大路径,以及下一个不包含这个边的节点
now=max(114-W[i],19)
包含与不包含这条边应该可以用LCA来判吧
但是这样枚举每条边还是O(n)的复杂度的,枚举每个Que也是O(n)的复杂度的
O(n^2)冲个锤子 

*/
