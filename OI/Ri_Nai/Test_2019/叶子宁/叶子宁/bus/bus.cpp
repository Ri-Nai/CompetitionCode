#include<cstdio>
#include<cstring>
#include<algorithm>
#define F
const int maxn=506,maxm=105;
int dp[maxn][maxm],sum[maxn][maxn],n,m,t[maxn];
//dp ��i���˵���jʱ��(��һ����)����С�ȴ�ʱ��� 
void pre()
{
	t[0]=-2e9;//��0���˲���Ҫ�ȴ� ��������˵Ĳ�ӦԽСԽ�� 
	scanf("%d%d",&n,&m);
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i)
		scanf("%d",&t[i]);
	std::sort(t+1,t+n+1);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=i;k<j;++k)
				sum[i][j]+=t[j]-t[k];
	//sum Ԥ������iΪ��� jΪ�յ�������� ȡjΪ������ ��Ҫ���⸶���ĵȴ�ʱ��
	for(int i=0;i<=m;++i)
		dp[0][i]=0,//��ʼ�� 
		dp[1][i]=i;//��1����ֻ��Ҫ�ȴ��Լ���ʱ�� 
}
void solve()
{
	pre();
	for(int i=2;i<=n;++i)//0 1 �Ѿ�������� ֻ��Ӷ���ʼ
						//��һ���������һ���� 
		for(int j=0;j<i;++j)//��һ���������һ���� 
			for(int k=0;k<=m;++k)//����һ��������kʱ��
			{
				int now=t[j]-t[i]+m+k;
				if(now<0)now=0;
				//printf("%d\n",now);
				//printf("%d %d\n",i,dp[i][now]);
				dp[i][now]=std::min(dp[i][now],dp[j][k]+sum[j+1][i]+(i-j)*now);
				//printf("%d\n",dp[i][now]);
			}
	int ans=2e9;
	for(int i=0;i<=m;++i)
		//printf("%d %d\n",ans,dp[n][i]),
		ans=std::min(dp[n][i],ans);
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
5 1
3 4 4 3 5
5 5
1 3 1 5 5
*/
