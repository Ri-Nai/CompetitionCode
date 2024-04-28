#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,A[N],B[N],len;
int nxt[N],to[N],head[N],tot;
int cnt[N<<2],mx[N<<2],ls[N<<2],rs[N<<2],RT[N],num;
inline void Add(int u,int v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
void Insert(int x,int k,int &rt,int L,int R)
{
	if(!rt)rt=++num;cnt[rt]+=k;
	if(L==R)
	{
		mx[rt]=cnt[rt]?x:0;
		return;
	}
	int mid=L+R>>1;
	if(x<=mid)Insert(x,k,ls[rt],L,mid);
	else Insert(x,k,rs[rt],mid+1,R);
	mx[rt]=max(mx[ls[rt]],mx[rs[rt]]);
}
int query(int x,int rt,int L,int R)
{
	if(mx[rt]<x)return -1;
	if(L==R)return L;
	int mid=L+R>>1;
	if(mx[ls[rt]]>=x)return query(x,ls[rt],L,mid);
	else return query(x,rs[rt],mid+1,R);
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	cnt[u]+=cnt[v];
	mx[u]=max(mx[u],mx[v]);
	ls[u]=Merge(ls[u],ls[v]);
	rs[u]=Merge(rs[u],rs[v]);
	return u;
}
void dfs(int u)
{
	for(int i=head[u],v;(v=to[i]);i=nxt[i])
		dfs(v),RT[u]=Merge(RT[u],RT[v]);
	int pos=query(A[u],RT[u],1,len);
	if(~pos)Insert(pos,-1,RT[u],1,len);
	Insert(A[u],1,RT[u],1,len);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u;i<=n;++i)scanf("%d%d",&A[i],&u),B[i]=A[i],Add(u,i);
	sort(B+1,B+1+n);len=unique(B+1,B+1+n)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+1+len,A[i])-B;
	dfs(1);printf("%d\n",cnt[RT[1]]);
}