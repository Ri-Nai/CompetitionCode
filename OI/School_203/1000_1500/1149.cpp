#include<cstdio>
#include<cstring>
int n,m,Q,f[40][25][25],ans[2][25];
int query(int A,int B,int K)
{
	memset(ans[0],0,sizeof ans[0]);
	int cur=0;ans[cur][A]=1;
	for(int t=30;~t;--t)
	{
		if((1<<t)&K)
		{
			memset(ans[cur^=1],0,sizeof ans[0]);
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					(ans[cur][i]+=ans[cur^1][j]*f[t][j][i]%1000)%=1000;
		}
	}

	return ans[cur][B];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),
		f[0][u][v]=1;
	for(int t=1;t<31;++t)
		for(int k=0;k<n;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					(f[t][i][j]+=f[t-1][i][k]*f[t-1][k][j])%=1000;
	scanf("%d",&Q);
	for(int i=1,A,B,K;i<=Q;++i)
		scanf("%d%d%d",&A,&B,&K),
		printf("%d\n",query(A,B,K));
}