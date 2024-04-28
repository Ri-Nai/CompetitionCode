#include <cstdio>
#include <cstring>
const int maxn=205;
char s[maxn],t[5][20][3],p[5]={0,'W','I','N','G'};
int n,L[5],to[256],dp[maxn][maxn][5];
bool dfs(int l,int r,int k)
{
	if(l==r)return s[l]==p[k];
	int &res=dp[l][r][k];
	if(~dp[l][r][k])return dp[l][r][k];
	for(int i=1;i<=L[k];++i)
		for(int j=l;j<r;++j)
			if(dfs(l,j,to[t[k][i][1]])&&dfs(j+1,r,to[t[k][i][2]]))
				return res=1;
	return res=0;
}
int main()
{
	memset(dp,-1,sizeof dp);
	to['W']=1,to['I']=2,to['N']=3,to['G']=4;
	for(int i=1;i<=4;++i)scanf("%d",&L[i]);
	for(int i=1;i<=4;++i)
		for(int j=1;j<=L[i];++j)
			scanf("%s",t[i][j]+1);
	scanf("%s",s+1);n=strlen(s+1);
	bool flag=0;
	for(int i=1;i<=4;++i)
		if(dfs(1,n,i))flag=1,putchar(p[i]);
	if(!flag)puts("The name is wrong!");
}