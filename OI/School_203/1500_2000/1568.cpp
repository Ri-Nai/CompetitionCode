#include<bits/stdc++.h>
using namespace std;
char s1[10000],s2[10000];
int main()
{
	scanf("%s%s",s1,s2);
	int len1=strlen(s1),len2=strlen(s2);
	int mn1=0,mn2=0,mx1=0,mx2=0;
	for(int i=0;i<len1;++i)
	{
		mx1=mx1*10+s1[i]-48;
		mn1=mn1*10+s1[i]-48;
		if(s1[i]=='5')++mx1;
		if(s1[i]=='6')--mn1;
	}
	for(int i=0;i<len2;++i)
	{
		mx2=mx2*10+s2[i]-48;
		mn2=mn2*10+s2[i]-48;
		if(s2[i]=='5')++mx2;
		if(s2[i]=='6')--mn2;
	}
	printf("%d %d\n",mn1+mn2,mx1+mx2);
}