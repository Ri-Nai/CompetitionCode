#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1050;
int n,m,K[maxn],P[maxn],dp[maxn],inf,
f[10][maxn],E[maxn],G,mark[maxn],tmp[maxn];
std::vector<int>V[10];
void ZO(int v,int w,int *dp)
{
	for(int i=m;i>=v;--i)if(dp[i-v]>inf)dp[i]=max(dp[i-v]+w,dp[i]);
}
void CP(int v,int w,int *dp)
{
	for(int i=v;i<=m;++i)if(dp[i-v]>inf)dp[i]=max(dp[i-v]+w,dp[i]);
}
void Clear()
{
	for(int i=1;i<=8;++i)V[i].clear();
	memset(mark,0,sizeof mark);
	memset(dp,-0x3f,sizeof dp);
	inf=dp[0];
	memset(f,-0x3f,sizeof f);dp[0]=0;
	for(int i=1;i<=8;++i)f[i][0]=0;
}
void in_put()
{
	for(int i=1;i<=n;++i)scanf("%d%d%d",&K[i],&E[i],&P[i]);
	scanf("%d",&G);
	for(int i=1;i<=G;++i)
	{
		int L;scanf("%d",&L);
		for(int j=1,x;j<=L;++j)
		{
			scanf("%d",&x);
			mark[x]=i;
			V[i].push_back(x);
		}
	}
}
void Bag(int id,int *dp)
{
	if(K[id]==0)CP(P[id],E[id],dp);
	else if(K[id]==1)ZO(P[id],E[id],dp);
	else
	{
		int sum=K[id],now=1;
		while(now<=sum)
			ZO(now*P[id],now*E[id],dp),
			sum-=now,now<<=1;
		if(sum)ZO(sum*P[id],sum*E[id],dp);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	Clear();
	in_put();
	for(int i=1;i<=n;++i)
		if(!mark[i])Bag(i,dp);
		else
		{
			memset(tmp,-0x3f,sizeof tmp);
			tmp[0]=0;Bag(i,tmp);
			for(int j=1;j<=m;++j)f[mark[i]][j]=max(f[mark[i]][j],tmp[j]);
		}
	for(int i=1;i<=G;++i)
		for(int j=m;j>=0;--j)
			for(int k=0;k<=j;++k)
				if(dp[j-k]>inf&&f[i][k]>inf)
					dp[j]=max(dp[j-k]+f[i][k],dp[j]);
	if(dp[m]>=0)printf("%d\n",dp[m]);
	else puts("i\'m sorry...");
}
