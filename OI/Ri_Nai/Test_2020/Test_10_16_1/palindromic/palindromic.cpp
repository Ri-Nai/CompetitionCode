#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
char s[N];int n;
bool chk(){for(int i=1;i<=n;++i)if(s[i]!='9')return 0;return 1;}
int Solve_9()
{
	++n;
	for(int i=1;i<=n;++i)
	{
		if(i==1||i==n)putchar('1');
		else putchar('0');
	}
	puts("");return 0;
}
int main()
{
//	FILE("palindromic");
	scanf("%s",s+1);
	n=strlen(s+1);
	if(chk())return Solve_9();
	bool flag=0;int pos=-1,ad=0,adp=0;
	for(int i=n+1>>1,j=n+2>>1;i>=1&&j<=n;--i,++j)
	{
		if(flag)
		{
			s[j]=s[i];
			continue;
		}
		if(s[i]==s[j])
		{
			if(s[i]!='9')
			{
				if(!~pos)pos=i;
			}
			else ad=1,adp=i;
			continue;
		}
		if(s[i]<s[j])
		{
			if(~pos)
			{
				++s[pos],s[n-pos+1]=s[pos],flag=1;--j;++i;
				for(int k=pos+1,md=n+1>>1;k<=md;++k)if(s[k]=='9')s[k]=s[n-k+1]='0';
				continue;
			}
			for(int k=i+1,md=n+1>>1;k<=md;++k)if(s[k]=='9')s[k]=s[n-k+1]='0';
			++s[i];
		}
		s[j]=s[i];flag=1;continue;
	}
	if(!flag)
	{
		for(int i=i=n+1>>1,j=n+2>>1;i>=1&&j<=n;--i,++j)
		{
			if(s[i]!='9')
			{
				s[j]=++s[i];
				break;
			}
			else s[j]=s[i]='0';
		}
	}
	for(int i=1;i<=n;++i)putchar(s[i]);
	puts("");
	FCLS();
}
/*
22121

*/
