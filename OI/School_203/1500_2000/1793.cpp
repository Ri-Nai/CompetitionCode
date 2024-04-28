#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=1;i+i<=len;++i)
	{
		if(len%i==0)
		{
			int sum[30]={};bool flag=1;
			for(int j=0;j<i;++j)++sum[s[j]-'a'];
			for(int j=i;j<len;j+=i)
			{
				int num[30]={};
				for(int k=j;k<j+i;++k)++num[s[k]-'a'];
				for(int k=0;k<26;++k)
					if(sum[k]!=num[k])
					{
						flag=0;break;
					}
			}
			if(flag)
			{
				for(int k=0;k<i;++k)putchar(s[k]);
				putchar('\n');return 0;
			}
		}
	}
	puts("-1");
}