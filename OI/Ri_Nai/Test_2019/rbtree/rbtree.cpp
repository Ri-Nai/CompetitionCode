#include<cstdio>
#include<vector>
#include<algorithm>
#define Fasdasd
std::vector<int>son[100];
int a[100],b[100],n,ans,to[100],cnt;
inline int max(const int &a,const int &b)
{
	return a>b?a:b;
}
inline int min(const int &a,const int &b)
{	
	return a<b?a:b;
}
int dfs(int now)
{
	if(!son[now].empty())
	{
		int res=dfs(son[now][0]);
		for(int i=1;i<son[now].size();++i)
			if(b[now])res=max(res,dfs(son[now][i]));
			else res=min(res,dfs(son[now][i]));
		return res;
	}
	return a[to[now]];
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=2,u;i<=n;++i)
		scanf("%d",&u),	
		son[u].push_back(i);
	for(int i=1;i<=n;++i)
		if(son[i].empty())
		{
			++cnt;
			a[cnt]=cnt;
			to[i]=cnt;
		}
	do 
		ans=max(dfs(1),ans);
	while(std::next_permutation(a+1,a+cnt+1));
	printf("%d\n",ans);	
}
int main()
{
	#ifndef F
	freopen("rbtree.in","r",stdin);
	freopen("rbtree.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
	
}
