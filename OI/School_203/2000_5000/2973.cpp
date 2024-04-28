#include<cstdio>
#include<cstring>
const int mod=1e9;
struct BIG
{
	int num[205],len;
	BIG(){memset(num,0,sizeof num);len=1;}
	void Add(BIG _)
	{
		if(_.len>len)len=_.len;
		for(int i=1;i<=len;++i)
		{
			num[i]+=_.num[i];
			num[i+1]+=num[i]/mod;
			num[i]%=mod;
		}
		while(num[len+1])++len;
	}
}dp[2][2005];
int n,m;
char s1[2005],s2[2005];
bool check(char a,char b)
{
	if(a=='T'&&b=='A')return 1;
	if(a=='A'&&b=='T')return 1;
	if(a=='C'&&b=='G')return 1;
	if(a=='G'&&b=='C')return 1;
	return 0;
}
int main()
{
	scanf("%d%d%s%s",&n,&m,s1+1,s2+1);
	for(int i=1;i<=n;++i)
	{
		dp[1][i].num[1]+=dp[1][i-1].num[1];
		if(check(s1[i],s2[1]))++dp[1][i].num[1];
	}
	for(int i=2;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dp[i&1][j]=BIG();
			dp[i&1][j].Add(dp[i&1][j-1]);
			if(check(s2[i],s1[j]))dp[i&1][j].Add(dp[i&1^1][j-1]);
		}
	}
	int i;
	for(i=200;;--i)if(dp[m&1][n].num[i])break;
	printf("%d",dp[m&1][n].num[i]);
	for(int j=i-1;j>=1;--j)
		printf("%09d",dp[m&1][n].num[j]);
}