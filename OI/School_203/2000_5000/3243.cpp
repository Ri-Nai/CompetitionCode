#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,lson[N<<1],rson[N<<1],A[N<<1],tot;
int ls[N*20],rs[N*20],RT[N<<1],sum[N*20],num;
long long ans,tmp,res;
int read()
{
	int now=++tot;
	scanf("%d",&A[now]);
	if(!A[now])
		lson[now]=read(),
		rson[now]=read();
	return now;
}
void Insert(int u,int &rt,int L=1,int R=n)
{
	rt=++num;++sum[rt];
	if(L==R)return;
	int mid=L+R>>1;
	if(u<=mid)Insert(u,ls[rt],L,mid);
	else Insert(u,rs[rt],mid+1,R);
}
int Merge(int u,int v)
{
	if(!u||!v)return u|v;
	res+=1ll*sum[ls[u]]*sum[rs[v]];
	sum[u]+=sum[v];
	ls[u]=Merge(ls[u],ls[v]);
	rs[u]=Merge(rs[u],rs[v]);
	return u;
}
void dfs(int u)
{
	if(A[u])Insert(A[u],RT[u]);
	else
	{
		int lp=lson[u],rp=rson[u];
		dfs(lp);dfs(rp);res=0;
		tmp=1ll*sum[RT[lp]]*sum[RT[rp]];
		RT[u]=Merge(RT[lp],RT[rp]);
		ans+=min(tmp-res,res);
	}
}
int main()
{
	scanf("%d",&n);
	read();dfs(1);
	printf("%lld\n",ans);
}