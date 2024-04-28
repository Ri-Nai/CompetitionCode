#include<cstdio>
int n,m,tot[10005],now,sum,
A[10005][105],B[10005][105];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j)
			scanf("%d%d",&A[i][j],&B[i][j]),tot[i]+=A[i][j];
	scanf("%d",&now);
	for(int i=1,x;i<=n;++i)
	{
		(sum+=x=B[i][now])%=20123;
		x%=tot[i];if(!x)x+=tot[i];
		//printf("%d %d\n",now,x);
		while(1)
		{
			if(A[i][now])--x;
			if(!x)break;
			if(++now>=m)now-=m;
			//printf("***%d***\n",now );
		}
	}
	printf("%d\n",sum);
}