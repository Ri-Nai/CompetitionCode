#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,A[N],nxt[N],head[N],to[N],tot,fa[N],Re[N];
int RT[N<<5],ls[N<<5],rs[N<<5],sum[N<<5],num;
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
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
	if(sum[rt]<x)return -1;
	if(L==R)return Re[L];int mid=L+R>>1;
	if(x<=sum[ls[rt]])return query(L,mid,x,ls[rt]);
	return query(mid+1,R,x-sum[ls[rt]],rs[rt]);
}
inline void MG()
{
	int u,v;scanf("%d%d",&u,&v);
	int fu=find(u),fv=find(v);
	if(fu!=fv)fa[fv]=fu,RT[fu]=Merge(RT[fu],RT[fv]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),Re[A[i]]=i,
		Insert(1,n,A[i],RT[i]),fa[i]=i;
	for(int i=1;i<=m;++i)MG();
	for(scanf("%d",&m);m--;)
	{
		char s[5];int u,v;scanf("%s",s);
		if(s[0]=='B')MG();
		else scanf("%d%d",&u,&v),printf("%d\n",query(1,n,v,RT[find(u)]));
	}
}