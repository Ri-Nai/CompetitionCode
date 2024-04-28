#include<cstdio>
#include<cstring>
#define Fasdasd
char s[int(1e5+5)];
int len;
void change(int &a)
{
	int ans=0;
	while(a)
	{
		ans+=a%10;
		a/=10;
	}
	a=ans;
}
void solve()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	if(len==1)
		puts("0");
	else
	{
		int now=0,cnt=1;
		for(int i=1;i<=len;++i)
			now+=s[i]^48;
		while(now>=10)change(now),++cnt;	
		printf("%d\n",cnt);
	}
}
int main()
{
	#ifndef F
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
