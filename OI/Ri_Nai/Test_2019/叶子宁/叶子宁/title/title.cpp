#include<cstdio>
#include<iostream>
#include<string>
#define Fasdasd
void solve()
{
	std::string s;
	long long ans=0;
	while(std::cin>>s)
		ans+=s.size();
	printf("%lld\n",ans);
}
int main()
{
	#ifndef F
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
