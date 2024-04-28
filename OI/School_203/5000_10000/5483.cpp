#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int RT[N<<4],ls[N<<5],rs[N<<5],sum[N<<5],lp[N<<5],rp[N<<5],num,n,m;
void Up(int rt)
{
	lp[rt]=lp[ls[rt]]?lp[ls[rt]]:lp[rs[rt]]; 
	rp[rt]=rp[rs[rt]]?rp[rs[rt]]:rp[ls[rt]];
	sum[rt]=sum[ls[rt]]+sum[rs[rt]]-(rp[ls[rt]]+1==lp[rs[rt]]); 
}
void Update(int &rt,int L,int R,int x)
{
	if(!rt)rt=++num;	
	if(L==R){lp[rt]=rp[rt]=x,sum[rt]=1;return;}
	int mid=L+R>>1;
	if(x<=mid)Update(ls[rt],L,mid,x);
	else Update(rs[rt],mid+1,R,x);
	Up(rt);
}
int Merge(int x,int y,int L,int R) 
{
	if(!x||!y)return x|y;
	if(L==R){lp[x]=rp[x]=L,sum[x]=1;return x;}
	int mid=L+R>>1;
	ls[x]=Merge(ls[x],ls[y],L,mid);
	rs[x]=Merge(rs[x],rs[y],mid+1,R);
	Up(x);return x;
}
int main()
{
	scanf("%d%d",&n,&m);int ans=0;
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),ans-=sum[RT[x]],
		Update(RT[x],1,n,i),ans+=sum[RT[x]];
	for(int k,u,v;m--;)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d",&u,&v);
			if(u==v)continue;
			ans-=sum[RT[u]]+sum[RT[v]];
			RT[v]=Merge(RT[v],RT[u],1,n);
			RT[u]=0;ans+=sum[RT[v]];
		}
		else printf("%d\n",ans);
	}
}