#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[10][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int T[2],D[2],mn=1e9,id;
bool mark[1440];
int read()
{
	int hh,mm;
	scanf("%d:%d",&hh,&mm);
	return hh*60+mm;
}
int main()
{
	T[0]=read();T[1]=read();D[0]=read();D[1]=read();
	if(T[1]<T[0])swap(T[1],T[0]),swap(D[1],D[0]);
	for(int i=1;;++i)
	{
		int now=D[1]*i+T[1];
		int tmp=(now-T[0])%D[0];
		if(tmp)
		{
			if(!mark[tmp])mark[tmp]=1;
			else return puts("Never"),0;
		}
		else
		{
			int Day=(now/1440+6)%7;
			puts(s[Day]);
			now%=1440;
			printf("%02d:%02d\n",now/60,now%60);
			return 0;
		}
	}
}
