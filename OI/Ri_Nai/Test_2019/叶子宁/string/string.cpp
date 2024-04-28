#include<iostream>
#include<string>
#define Fasdasd
std::string s,t;
int n,ans;
bool flag;
void solve()
{
	std::cin>>n>>s>>t;
	int l=0,r=n-1;
	while(l<n&&s[l]==t[l])++l;
	while(~r&&s[r]==t[r])--r;
	for(int i=l,j=r;i<=j;++i,--j)
	{
		if(s[i]!=t[j])
		{
			flag=1;
			break;
		}
	}
	if(flag)std::cout<<0<<std::endl;
	else
	{
		ans=1;
		--l,++r;
		while(~l&&r<n&&s[l]==s[r])--l,++r,++ans;
		std::cout<<ans<<std::endl;
	}
}
int main()
{
	#ifndef F
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
