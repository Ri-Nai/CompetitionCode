#include<cstdio>
#include<cstring>
#define LL long long
LL HD,dp[505][2][2][2];
int n,num[12]={6,2,5,5,4,5,6,3,7,6};
LL dfs(int rest,int is,int isa,int isb)
{
	if(~dp[rest][is][isa][isb])return dp[rest][is][isa][isb];
	if(!isa&&!isb)
	{
		if(!is&&!rest)return 1;
		if(is&&rest==num[1])return 1;
		return 0;
	}
	LL res=0;
	if(isa&&isb)
	{
		for(int i=0;i<=9;++i)
			for(int j=0;j<=9;++j)
			{
				int tmp=i+j+is,flag=0,k=0;
				if(tmp>=10)tmp-=10,flag=1;
				k=rest-num[tmp]-num[i]-num[j];
				if(k>=0)
				{
					(res+=dfs(k,flag,1,1))%=HD;
					if(i)(res+=dfs(k,flag,0,1))%=HD;
					if(j)(res+=dfs(k,flag,1,0))%=HD;
					if(i&&j)(res+=dfs(k,flag,0,0))%=HD;
				}
			}
	}
	else
	{
		for(int i=0;i<=9;++i)
		{
			int tmp=i+is,flag=0,k=0;
			if(tmp>=10)tmp-=10,flag=1;
			k=rest-num[tmp]-num[i];
			if(k>=0)
			{
				if(isa)
				{
					(res+=dfs(k,flag,1,0))%=HD;
					if(i)(res+=dfs(k,flag,0,0))%=HD;
				}
				if(isb)
				{
					(res+=dfs(k,flag,0,1))%=HD;
					if(i)(res+=dfs(k,flag,0,0))%=HD;
				}
			}
		}
	}
	return dp[rest][is][isa][isb]=res;
}
int main()
{
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)
		scanf("%d%lld",&n,&HD),memset(dp,-1,sizeof dp),
		printf("Case #%d: %lld\n",i,dfs(n-3,0,1,1));
}