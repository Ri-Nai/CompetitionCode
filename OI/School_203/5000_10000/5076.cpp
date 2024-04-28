#include<cstdio>
#include<cstring>
#include<algorithm>
int k,n;
struct $
{
	int B,P;
	void read()
	{
		B=0;scanf("%d",&P);
		while(1)
		{
			int x;scanf("%d",&x);
			if(!x)break;B|=1<<x-1;
		}
	}
}A[20];
double dp[105][1<<16];
bool vis[105][1<<16];
long long ans=0;
double dfs(int k,int state)
{
	if(k==0)return 0;
	if(vis[k][state])return dp[k][state];
	vis[k][state]=1;
	double res=0;
	for(int i=0;i<n;++i)
	{
		double tmp=dfs(k-1,state);
		if((state&A[i].B)==A[i].B)
			tmp=std::max(tmp,(dfs(k-1,state|1<<i)+A[i].P));
		res+=tmp/n;
	}
	dp[k][state]=res;
	return res;
}
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;++i)A[i].read();
	printf("%.6f\n",dfs(k,0));
}
/*
2 3
-1 0
5 1 0
1 0
*/