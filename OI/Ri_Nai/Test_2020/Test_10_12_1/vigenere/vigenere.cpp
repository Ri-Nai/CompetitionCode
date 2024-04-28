#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
char s1[2005],s2[2005];
char Get(char c1,char c2)
{
	return (26+(c2-'A')-(c1-'A'))%26+'A';
}
int main()
{
	FILE("vigenere");
	scanf("%s%s",s1,s2);
	int n=strlen(s1),m=strlen(s2);
	for(int i=0;i<m;++i)
	{
		int j=i%n;
		char c=Get(toupper(s1[j]),toupper(s2[i]));
		if(islower(s2[i]))putchar(tolower(c));
		else putchar(c);
	}
	FCLS();
}
/*
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

*/