#include<cstdio>
#include<cstring>
int n,m,K,P,sum[2005],cnt[2005],tot;
char s[2005];
int main()
{
	scanf("%d%d%d",&m,&K,&P);
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+(s[i]=='Q');
		if(i>=K)
			if(sum[i]-sum[i-K]>=P)
			{
				for(int j=i-K+1;j<=i;++j)
					++cnt[j];
				++tot;
			}
	}
	for(int i=1;i<=n;++i)
		if(tot-cnt[i]<m)putchar('+');
		else if(cnt[i]==0)putchar('-');
		else putchar('?');
}