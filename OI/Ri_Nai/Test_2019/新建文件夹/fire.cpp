#include<cstdio>
#include<cstring>
#include<algorithm>
#define F
const int maxn=105,inf=0x3f3f3f3f;
int n,m,t,a[maxn],L,v1,v2,v3;
double sum[maxn],now;
void solve()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d",&L,&n,&m,&t,&v1,&v2,&v3);
		memset(sum,0,sizeof sum);
		memset(a,0,sizeof a);
		a[0]=0,a[n+1]=L;
		sum[0]=0;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n+1;++i)
		{
			sum[i]=inf;
			for(int j=0;j<i;++j)
			{
				int dis=a[i]-a[j];
				if(dis>m)now=m*1.0/v2+(dis-m)*1.0/v3;
				else now=dis*1.0/v2;
				if(j!=0)now+=t;
				sum[i]=std::min(sum[i],sum[j]+now);
			}
		}
		if(sum[n+1]*v1<L)puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
}
int main()
{
	#ifndef F
	freopen("fire.in","r",stdin);
	freopen("fire.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
