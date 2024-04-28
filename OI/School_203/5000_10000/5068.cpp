#include <cstdio>
#include <cstring>
#include <algorithm>
char s[100];
int dp[60][60][2];
bool check(int l,int r)
{
	int len=r-l+1;
	if(len&1)return 0;
	for(int i=l;i<=(l+r)/2;++i)
	if(s[i]!=s[i+len/2])return 0;
	return 1;
 }
int dfs(int l,int r,bool t)
{
    int len=r-l+1;if(len==1)return 1;
    if(~dp[l][r][t])return dp[l][r][t];
    if(t)for(int i=l;i<r;++i)len=std::min(len,dfs(l,i,1)+dfs(i+1,r,1)+1);
	for(int i=l;i<r;++i)len=std::min(len,dfs(l,i,t)+r-i);
    if(check(l,r))len=std::min(len,dfs(l,l+r>>1,0)+1);
    return dp[l][r][t]=len;
}
int main()
{
	memset(dp,-1,sizeof dp);
    scanf("%s",s+1);
    int len=strlen(s+1);
    printf("%d\n",dfs(1,len,1));
}