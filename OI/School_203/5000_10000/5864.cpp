#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn=5e5+5;
char s[maxn];
int n,now,sz[maxn],son[3][maxn],fa[maxn],mx[4][maxn],mn[4][maxn],ans1,ans2;
int build()
{
	int k=++now;
	for(int i='1';i<=s[k];++i)
	{
		int t=build();
		//printf("%d %d\n",k);
		son[++sz[k]][k]=t;fa[t]=k;
	}
	return k;
}
void in_put()
{
	scanf("%s",s+1);n=strlen(s+1);
	fa[1]=-1;build();
	// for(int i=1;i<=n;++i)
	// 	printf("%d\n",fa[i]);
}
void dfs(int now)
{
	if(sz[now]==2)
	{
		int l,r;dfs(l=son[1][now]);dfs(r=son[2][now]);
		mx[1][now]=std::max(mx[2][l]+mx[3][r],mx[3][l]+mx[2][r]);
		mx[2][now]=std::max(mx[1][l]+mx[3][r],mx[3][l]+mx[1][r]);
		mx[3][now]=std::max(mx[1][l]+mx[2][r],mx[2][l]+mx[1][r])+1;

		mn[1][now]=std::min(mn[2][l]+mn[3][r],mn[3][l]+mn[2][r]);
		mn[2][now]=std::min(mn[1][l]+mn[3][r],mn[3][l]+mn[1][r]);
		mn[3][now]=std::min(mn[1][l]+mn[2][r],mn[2][l]+mn[1][r])+1;
	}
	else if(sz[now]==1)
	{
		int nxt=son[1][now];dfs(nxt);
		mx[1][now]=std::max(mx[2][nxt],mx[3][nxt]);
		mx[2][now]=std::max(mx[1][nxt],mx[3][nxt]);
		mx[3][now]=std::max(mx[1][nxt],mx[2][nxt])+1;

		mn[1][now]=std::min(mn[2][nxt],mn[3][nxt]);
		mn[2][now]=std::min(mn[1][nxt],mn[3][nxt]);
		mn[3][now]=std::min(mn[1][nxt],mn[2][nxt])+1;
	}
	else
	{
		mx[1][now]=mx[2][now]=0;mx[3][now]=1;

		mn[1][now]=mn[2][now]=0;mn[3][now]=1;
	}
	if(now==1)
		ans1=std::min(mn[1][1],std::min(mn[2][1],mn[3][1])),
		ans2=std::max(mx[1][1],std::max(mx[2][1],mx[3][1]));
}
int main()
{
	in_put();
	dfs(1);
	printf("%d %d\n",ans2,ans1);
}