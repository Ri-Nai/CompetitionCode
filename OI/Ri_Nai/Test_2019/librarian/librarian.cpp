#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#define Fasdasd
int n,q;
std::string s[1005];
bool cmp(std::string s1,std::string s2)
{
	if(s1.size()!=s2.size())return s1.size()<s2.size();
	return s1<s2;
}
void pre()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		std::cin>>s[i];
	std::sort(s+1,s+1+n,cmp);
}
void solve()
{
	pre();
	while(q--)
	{
		int bit;
		std::string t;
		scanf("%d",&bit);
		std::cin>>t;
		for(int i=1;i<=n;++i)
		{
			if(s[i].size()>=bit)
				if(s[i].substr(s[i].size()-bit)==t)
				{
					std::cout<<s[i]<<"\n";
					goto nxt;
				}
		}
		puts("-1");
		nxt:;
	}
}
int main()
{
	#ifndef F
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
