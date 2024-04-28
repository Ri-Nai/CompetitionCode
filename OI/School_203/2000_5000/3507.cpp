#include<cstdio>
int val[55],n,ans;
bool vis[55],mark[1024],is[55][55];
void dfs(int now)
{
	vis[now]=1;
	for(int i=1;i<=n;++i)
		if(!vis[i]&&is[now][i])dfs(i);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1;i<=n;++i)
	{
		char s[55];scanf("%s",s+1);
		for(int j=1;j<=n;++j)
			if(s[j]=='Y')is[i][j]=1;
	}
	dfs(1);mark[val[1]]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=1023;++j)
			if(vis[i]&&mark[j])mark[val[i]^j]=1;
	for(int i=1023;~i;--i)
		if(mark[i])
		{
			printf("%d\n",i);
			break;
		}
}