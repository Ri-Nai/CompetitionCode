#include<cstdio>
const int maxn=505;
int n,m,sum1[maxn][maxn],sum2[maxn][maxn];
char s[maxn];
bool mp[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			mp[i][j]=(s[j]=='.');
	}
	for(int i=1;i<=n;++i)
	{

		for(int j=1;j<=m;++j)
		{
			sum1[i][j]=sum1[i][j-1];
			if(mp[i][j]==mp[i][j-1]&&mp[i][j])++sum1[i][j];
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			sum2[i][j]=sum2[i][j-1];
			if(mp[j][i]==mp[j-1][i]&&mp[j][i])++sum2[i][j];
		}

	int q;scanf("%d",&q);
	while(q--)
	{
		int x1,x2,y1,y2,ans=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i=x1;i<=x2;++i)ans+=sum1[i][y2]-sum1[i][y1];
		for(int i=y1;i<=y2;++i)ans+=sum2[i][x2]-sum2[i][x1];
		printf("%d\n",ans);

	}
}