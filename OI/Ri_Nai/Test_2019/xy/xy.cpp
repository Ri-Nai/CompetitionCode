#include<map>
#include<cstdio>
#define Fasdasd
int ans,n;
std::map<int,bool> mp;
void dfs(long long now,int a,int b)
{
	if(now>n)return;
	if(!mp[now]&&now)
		mp[now]=1,
		++ans;
	if(now||a)dfs(now*10+a,a,b);
	if(now||b)dfs(now*10+b,a,b);
}
void solve()
{
	scanf("%d",&n);
	for(int i=0;i<=9;++i)
		for(int j=i;j<=9;++j)
			dfs(0,i,j);
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("xy.in","r",stdin);
	freopen("xy.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
