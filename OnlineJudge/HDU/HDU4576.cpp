#include<cstdio>
#include<cstring>
double dp[2][200005];
int n,m,l,r;
inline int id(int k)
{
	while(k>n)k-=n;
	while(k<=0)k+=n;
	return k;
}
int rd()
{
	int x=0,c=0;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main()
{
	while(1)
	{
		n=rd();m=rd();l=rd();r=rd();
		if(!n)break;
		int cur=0;
		for(register int j=1;j<=n;++j)dp[cur][j]=0;
		dp[cur][1]=1;
		for(register int i=1,w;i<=m;++i)
		{
			w=rd();cur^=1;
			//for(int j=1;j<=n;++j)dp[cur][j]=0;
			//memset(dp[cur],0,sizeof dp[0]);
			for(register int j=1;j<=n;++j)
				dp[cur][j]=0.5*dp[cur^1][id(j+w)]+0.5*dp[cur^1][id(j-w)];
				//dp[cur][id(j+w)]+=0.5*dp[cur^1][j],
				//dp[cur][id(j-w)]+=0.5*dp[cur^1][j];
		}
		double sum=0.0;
		for(register int i=l;i<=r;++i)sum+=dp[cur][i];
		printf("%.4f\n",sum);
	}
}