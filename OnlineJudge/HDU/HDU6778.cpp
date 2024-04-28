#pragma GCC optimize(2)
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn=1e4+5;
int n,cnt[20],val[6],ans=0;
char tmp[10];
void dfs(int index)
{
	if(index==10)
	{
		int tmp=1e9;
		for(int i=1;i<=5;++i)
			if(val[i]<tmp)tmp=val[i];
		if(tmp>ans)ans=tmp;
		return ;
	}
	val[1]+=cnt[index];
	dfs(index+1);
	val[1]-=cnt[index];
	val[2]+=cnt[index];
	dfs(index+1);
	val[2]-=cnt[index];
	val[3]+=cnt[index];
	dfs(index+1);
	val[3]-=cnt[index];
	val[4]+=cnt[index];
	dfs(index+1);
	val[4]-=cnt[index];
	val[5]+=cnt[index];
	dfs(index+1);
	val[5]-=cnt[index];
}
void solve()
{
	memset(cnt,0,sizeof cnt);ans=0;
	scanf("%d",&n);int tot=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",tmp);
		++cnt[tmp[4]-'0'];
		++tot;
	}
	dfs(0);
	printf("%d\n",tot-ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}