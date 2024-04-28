#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int RT[N<<5],ls[N<<5],rs[N<<5],sum[N<<5],num;
int nxt[N],head[N],to[N],tot,n,A[N],B[N],ans[N],len;
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	sum[u]+=sum[v];
	ls[u]=Merge(ls[u],ls[v]);
	rs[u]=Merge(rs[u],rs[v]);
	return u;
}
void Insert(int L,int R,int x,int &rt)
{
	rt=++num;sum[rt]=1;
	if(L==R)return;int mid=L+R>>1;
	if(x<=mid)Insert(L,mid,x,ls[rt]);
	else Insert(mid+1,R,x,rs[rt]);
}
int query(int L,int R,int x,int rt)
{
	if(L==R)return sum[rt];
	int mid=L+R>>1;
	if(x<=mid)return sum[rs[rt]]+query(L,mid,x,ls[rt]);
	else return query(mid+1,R,x,rs[rt]);
}
void dfs(int u)
{
	Insert(1,n,A[u],RT[u]);
	for(int i=head[u];i;i=nxt[i])
	{
		int &v=to[i];dfs(v);
		RT[u]=Merge(RT[u],RT[v]);
	}
	if(A[u]<len)ans[u]=query(1,n,A[u]+1,RT[u]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+n+1,A[i])-B;
	for(int i=2,u;i<=n;++i)scanf("%d",&u),Add(u,i);
	dfs(1);for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
}