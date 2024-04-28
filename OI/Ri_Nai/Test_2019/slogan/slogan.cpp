#include<cstdio>
#include<cctype>
#include<cstring>
#define Fasdasd
const int maxn=1e5+5;
int n,a[maxn],sum;
char tmp[205];
void solve()
{
	scanf("%d",&n);
	for(int i=1,len;i<=n;++i)
	{
		scanf("%s",tmp);
		len=strlen(tmp);
		for(int j=0;j<len;++j)
			if(islower(tmp[j]))
				++a[i];
		sum+=a[i];
	}
	if(sum%10!=0)printf("%d\n",sum);
	else
	{
		int mn=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
			if(a[i]%10!=0&&a[i]<mn)
				mn=a[i];
		}
		if(mn==0x3f3f3f3f)
			puts("0");
		else printf("%d\n",sum-mn);
	}
}
int main()
{
	#ifndef F
	freopen("slogan.in","r",stdin);
	freopen("slogan.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}

