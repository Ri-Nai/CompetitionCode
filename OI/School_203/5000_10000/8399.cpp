#include<bits/stdc++.h>
#define Lson ls[rt],L,mid
#define Rson rs[rt],mid+1,R
#define LW(x) x=lower_bound(C+1,C+len+1,x)-C;
using namespace std;
double lg[N],pro[N*30];
int m,n,c[N],A[N],B[N],C[N<<1],len,fa[N];
int RT[N],ls[N*30],rs[N*30],sz[N*30],tot;
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void Insert(int u,int v,double w,int &rt,int L=1,int R=len)
{
	if(!rt)rt=++tot;
	sz[rt]+=v;
	pro[rt]+=w;
	if(L==R)return ;
	int mid=L+R>>1;
	if(u<=mid)Insert(u,v,w,Lson);
	else Insert(u,v,w,Rson);
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	sz[u]+=sz[v];pro[u]+=pro[v];
	ls[u]=Merge(ls[u],ls[v]);
	rs[u]=Merge(rs[u],rs[v]);
	return u;
}
int Del(int l,int r,int &rt,int L=1,int R=len)
{
	if(!rt)return 0;
	if(r<l)return 0;
	if(!sz[rt])return 0;
	if(L==R)
	{
		int tmp=sz[rt];
		sz[rt]=pro[rt]=0;
		return tmp;
	}
	int mid=L+R>>1,ans=0;
	if(l<=mid)ans=Del(l,r,Lson);
	if(r>mid)ans+=Del(l,r,Rson);
	sz[rt]=sz[ls[rt]]+sz[rs[rt]];
	pro[rt]=pro[ls[rt]]+pro[rs[rt]];
	return ans;
}
int query(int k,int rt,int L=1,int R=len)
{
	if(L==R)return C[L];int mid=L+R>>1;
	if(k<=sz[ls[rt]])return query(k,Lson);
	return query(k-sz[ls[rt]],Rson);
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&c[i]);
		if(c[i]==1)scanf("%d",&A[i]),C[++len]=A[i];
		else if(c[i]==7)scanf("%d",&A[i]);
		else
		{
			scanf("%d%d",&A[i],&B[i]);
			if(c[i]==3||c[i]==4)C[++len]=B[i];
		}
	}
	sort(C+1,C+len+1);len=unique(C+1,C+len+1)-C-1;
	for(int i=1;i<=len;++i)lg[i]=log10(C[i]);
	for(int i=1;i<=m;++i)
	{
		if(c[i]==1)
		{
			++n;LW(A[i]);fa[n]=n;
			Insert(A[i],1,lg[A[i]],RT[n]);
		}
		if(c[i]==2)
		{
			int u=find(A[i]),v=find(B[i]);
			if(u!=v)fa[u]=v,RT[v]=Merge(RT[v],RT[u]);
		}
		if(c[i]==3)
		{
			int u=find(A[i]);LW(B[i]);
			int num=Del(1,B[i]-1,RT[u]);
			if(num)Insert(B[i],num,lg[B[i]]*num,RT[u]);
		}
		if(c[i]==4)
		{
			int u=find(A[i]);LW(B[i]);
			int num=Del(B[i]+1,len,RT[u]);
			if(num)Insert(B[i],num,lg[B[i]]*num,RT[u]);
		}
		if(c[i]==5)printf("%d\n",query(B[i],RT[find(A[i])]));
		if(c[i]==6)puts(find(A[i])!=find(B[i])&&pro[RT[find(A[i])]]>pro[RT[find(B[i])]]-1e-6?"1":"0");
		if(c[i]==7)printf("%d\n",sz[RT[find(A[i])]]);
	}
}