#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e5+5;
int n,m,Q,A[N],B[N],len,ans[M],fa[N];
int RT[N],ls[N*20],rs[N*20],sum[N*20],num;
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
struct Edge
{
	int u,v,w,id;
	bool operator <(Edge _)const
	{
		return w<_.w;
	}
}E[M],P[M];
void Insert(int L,int R,int x,int &rt)
{
	rt=++num;sum[rt]=1;
	if(L==R)return;int mid=L+R>>1;
	if(x<=mid)Insert(L,mid,x,ls[rt]);
	else Insert(mid+1,R,x,rs[rt]);
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	sum[u]+=sum[v];
	ls[u]=Merge(ls[u],ls[v]);
	rs[u]=Merge(rs[u],rs[v]);
	return u;
}
int query(int L,int R,int x,int rt)
{
	if(x<=0)return -1;
	if(L==R)return B[L];int mid=L+R>>1;
	if(x<=sum[ls[rt]])return query(L,mid,x,ls[rt]);
	return query(mid+1,R,x-sum[ls[rt]],rs[rt]);
}
void _Union(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv)fa[fv]=fu,RT[fu]=Merge(RT[fu],RT[fv]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i],fa[i]=i;
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)
		Insert(1,len,A[i]=lower_bound(B+1,B+len+1,A[i])-B,RT[i]);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	for(int i=1;i<=Q;++i)
		scanf("%d%d%d",&P[i].u,&P[i].w,&P[i].v),P[i].id=i;
	sort(E+1,E+m+1);sort(P+1,P+Q+1);int now=1;
	for(int i=1;i<=Q;++i)
	{
		while(now<=m&&E[now].w<=P[i].w)
			_Union(E[now].u,E[now].v),++now;
		int Rt=RT[find(P[i].u)];
		ans[P[i].id]=query(1,len,sum[Rt]-P[i].v+1,Rt);
	}
	for(int i=1;i<=Q;++i)printf("%d\n",ans[i]);
}