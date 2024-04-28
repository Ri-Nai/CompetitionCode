#include<iostream>
#include<cstdio>
#define F
void solve()
{
	char now=0,last;
	long long num,ans=0,tmp;
	while(1)
	{
		std::cin>>num;
		now=getchar();
		if(now==EOF)
			break;
		if(!last)
			tmp=num;
		else
			switch(last)
			{
				case'+':ans+=tmp;ans%=10000;tmp=num;break;
				case'*':tmp*=num;tmp%=10000;break;
			}
		last=now;
	}
	ans+=tmp;
	ans%=10000;
	std::cout<<ans;
}
int main()
{
	#ifndef F
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	#endif 
	solve();
	fclose(stdin);
	fclose(stdout);
}
