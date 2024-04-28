#include<cstdio>
#include<cstring>
int dp[35][35],root[35][35],A[35],n;
int dfs(int L,int R)
{
	if(L==R){root[L][R]=R;return dp[L][R]=A[L];}
	if(L>R)return 1;
	if(~dp[L][R])return dp[L][R];
	int res=0;
	for(int i=L;i<=R;++i)
	{
		if(A[i]+dfs(L,i-1)*dfs(i+1,R)>res)
			res=A[i]+dfs(L,i-1)*dfs(i+1,R),
			root[L][R]=i;
	}
	return dp[L][R]=res;
}
void print(int L,int R)
{
	if(L>R)return;
	printf("%d ",root[L][R]);
	print(L,root[L][R]-1),print(root[L][R]+1,R);
}
int main()
{
	memset(dp,-1,sizeof dp);scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	printf("%d\n",dfs(1,n));print(1,n);
}