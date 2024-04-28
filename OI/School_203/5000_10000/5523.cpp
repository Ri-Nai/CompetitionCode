#include<bits/stdc++.h>
#pragma GCC optimize(2)
const int mod=1e6;
int dp[39][39][39][39][5][5];
int n,b1,b2,b3,b4;
int dfs(int b1,int b2,int b3,int b4,int pre1,int pre2)
{
	if(!(b1+b2+b3+b4))return 1;
	if(~dp[b1][b2][b3][b4][pre1][pre2])return dp[b1][b2][b3][b4][pre1][pre2];
	int res=0;
	bool f1=0,f2=0,f3=0,f4=0;
	if((pre1==1||pre1==2)&&(pre2==1||pre2==2))f1=1;
    if((pre1==3||pre1==4)&&(pre2==3||pre2==4))f2=1;
    if((pre1==1||pre1==3)&&(pre2==1||pre2==3))f3=1;
    if((pre1==4||pre1==2)&&(pre2==4||pre2==2))f4=1;
	if(b1&&!(f1|f3))res+=dfs(b1-1,b2,b3,b4,1,pre1);
	if(b2&&!(f1|f4))res+=dfs(b1,b2-1,b3,b4,2,pre1);
	if(b3&&!(f2|f3))res+=dfs(b1,b2,b3-1,b4,3,pre1);
	if(b4&&!(f2|f4))res+=dfs(b1,b2,b3,b4-1,4,pre1);
	return dp[b1][b2][b3][b4][pre1][pre2]=res%mod;
}
int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d%d%d%d",&b1,&b2,&b3,&b4);
	printf("%d\n",dfs(b1,b2,b3,b4,0,0));
}