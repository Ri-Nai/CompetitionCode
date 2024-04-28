#include<bits/stdc++.h>
using namespace std;
char s[1505];
void print(int cnt)
{
	for(int j=0;j<cnt;++j)putchar(' ');
}
int main()
{
	scanf("%s",s);
	int len=strlen(s),cnt=0;
	for(int i=0;i<len;++i)
	{
		if(s[i]=='}')
		{
			cnt-=2;
			if(!(i&&s[i-1]=='{'))puts("");
			print(cnt);
			putchar('}');
		}
		else if(s[i]=='{')
		{
			cnt+=2;
			puts("{");
			if(s[i+1]!='}')print(cnt);
		}
		else if(s[i]==',')
		{
			puts(",");
			print(cnt);
		}
		else putchar(s[i]);
	}
}