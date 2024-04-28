#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
const int maxn=1e4+5;
int n;
std::string S[maxn],ans;
bool cmp(std::string A,std::string B)
{
	return A+B<B+A;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		std::cin>>S[i];
	std::sort(S+1,S+1+n,cmp);
	for(int i=1;i<=n;++i)
		ans+=S[i];
	int now=0;
	while(now<ans.size()&&ans[now]=='0')++now;
	if(now<ans.size())
		for(int i=now;i<ans.size();++i)
			putchar(ans[i]);
	else putchar('0');
}