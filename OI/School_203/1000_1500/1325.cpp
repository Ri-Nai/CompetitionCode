#include<cstdio>
int A[305][305],n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%1d",&A[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			int num=0;
			for(int k=1;k<=n;++k)
				num+=(A[i][k]&A[j][k]);
			ans+=num*(num-1)/2;
		}
	printf("%d\n",ans);
}