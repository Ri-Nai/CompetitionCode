#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int RT[N],ls[N<<5],rs[N<<5],sum[N<<5],num,rt;
int n,m,Q,A[N],B[N],len,fa[N],val[N],f[25][N];
int find(int u)
{
	while(u!=fa[u])u=fa[u]=fa[fa[u]];return u;
}
struct Edge
{
	int u,v,w;
	bool operator <(Edge _)const{return w<_.w;}
}E[(N>>1)+(N<<1)];
void Insert(int x,int &rt,int L=1,int R=len)
{
	rt=++num;sum[rt]=1;
	if(L==R)return;int mid=L+R>>1;
	if(x<=mid)Insert(x,ls[rt],L,mid);
	else Insert(x,rs[rt],mid+1,R);
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	int now=++num;
	sum[now]=sum[u]+sum[v];
	ls[now]=Merge(ls[u],ls[v]);
	rs[now]=Merge(rs[u],rs[v]);
	return now;
}
int query(int x,int rt,int L=1,int R=len)
{
	if(x<=0)return -1;
	if(L==R)return B[L];int mid=L+R>>1;
	if(x<=sum[ls[rt]])return query(x,ls[rt],L,mid);
	else return query(x-sum[ls[rt]],rs[rt],mid+1,R);
}
inline void _Union(int u,int v,int w)
{
	u=find(u),v=find(v);
	if(u!=v)
	{
		fa[v]=fa[u]=++rt;
		f[0][u]=f[0][v]=rt;
		fa[rt]=rt;val[rt]=w;
		RT[rt]=Merge(RT[u],RT[v]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);rt=n;
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i],fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	sort(E+1,E+m+1);sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B,Insert(A[i],RT[i]);
	for(int i=1;i<=m;++i)_Union(E[i].u,E[i].v,E[i].w);
	for(int i=1;i<=20;++i)
		for(int j=1;j<=rt;++j)
			f[i][j]=f[i-1][f[i-1][j]];
	for(int i=1;i<=Q;++i)
	{
		int u,w,k;scanf("%d%d%d",&u,&w,&k);
		for(int j=20;~j;--j)
			if(f[j][u]&&val[f[j][u]]<=w)u=f[j][u];
		printf("%d\n",query(sum[RT[u]]-k+1,RT[u]));
	}
}