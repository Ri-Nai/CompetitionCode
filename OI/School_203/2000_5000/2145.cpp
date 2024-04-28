#include<cstdio>
#include<vector>
#include<algorithm>
const int maxn=20;
struct ${int G,A;};
int n,m,s[20][20],dp[1<<20],ans,cnt[1<<20];
std::vector<$>P[20];
void in_put()
{
	scanf("%d%d",&n,&m);
	for(int i=1,p,g,a;i<=m;++i)
		scanf("%d%d%d",&p,&g,&a),
		P[p].push_back(($){g,a});
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&s[i][j]);
	for(int i=1;i<(1<<n);++i)
		cnt[i]=cnt[i>>1]+(i&1);
		//printf("%d %d\n",i,cnt[i]);
}
int main()
{
	in_put();
	for(int i=0;i<(1<<n);++i)
	{
		int now=cnt[i]+1;
		for(int j=0;j<n;++j)
			if(!((i>>j)&1))
			{
				int tmp=dp[i]+s[j][now-1],sum=0;
				for(int k=0;k<P[now].size();++k)
					if(tmp>=P[now][k].G)sum+=P[now][k].A;
				//printf("%d %d\n",tmp,sum);
				if(tmp+sum>dp[i|(1<<j)])dp[i|(1<<j)]=tmp+sum;
			}
	}
	printf("%d\n",dp[(1<<n)-1]);
}