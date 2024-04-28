#include<cstdio>
int cnt[1005],n,x,sum;
double ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&x),++cnt[x];
	for(int i=1;i<=1000;++i)ans+=1.0*cnt[i]*(n+1)/(n-sum+1),sum+=cnt[i];
	printf("%.2f\n",ans);
}