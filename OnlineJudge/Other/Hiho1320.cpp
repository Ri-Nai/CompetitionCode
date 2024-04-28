#include <cstdio>
#include <cstring>
#include <algorithm>
char s[105];
int dp[105][105];
int bit(int n){int k=0;do n/=10,++k;while(n);return k;}
int len(int l,int r)
{
	int now=r-l+1,res=now;
	for(int i=1;i<=now;++i)
		if(now%i==0)
		{
			for(int j=l,cnt=0;j<=r;++j,++cnt,cnt%=i)
				if(s[j]!=s[l+cnt])
					goto nxt;
			res=std::min(res,dp[l][l+i-1]+bit(now/i)+2);nxt:;
		}
	//if(l==1&&r==6)printf("%d\n",res);
	return res;
}
void solve()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	//printf("%d\n",n);
	memset(dp,0x3f,sizeof dp);
	for(int l=1;l<=n;++l)
	{
		for(int i=1,j=l;j<=n;++i,++j)
		{
			dp[i][j]=len(i,j);
			//if(i==j)printf("%d\n",dp[i][j]);
			for(int k=i;k<=j;++k)
				dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	}
	printf("%d\n",dp[1][n]);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}