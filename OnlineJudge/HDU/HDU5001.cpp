#include<cstdio>
#include<cstring>
double dp[2][55];
int n,m,d,mp[55][55],cnt[55];
void Clear()
{
	memset(mp,0,sizeof mp);
	memset(cnt,0,sizeof cnt);
}
void in_put()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=mp[v][u]=1;
		++cnt[v];++cnt[u];
		//if(u!=v)++cnt[u];
	}
}
void solve()
{
	Clear();in_put();
	for(int u=1;u<=n;++u)
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;++i)dp[0][i]=1.0/n;
		for(int i=1;i<=d;++i)
		{
			int cur=i&1;
			memset(dp[cur],0,sizeof dp[cur]);
			for(int j=1;j<=n;++j)
				for(int k=1;k<=n;++k)
					if(j!=u&&mp[j][k])
						dp[cur][k]+=dp[cur^1][j]/cnt[j];
		}
		double ans=0;
		for(int i=1;i<=n;++i)
			if(i!=u)ans+=dp[d&1][i];
		printf("%.10lf\n",ans);
	}

}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}