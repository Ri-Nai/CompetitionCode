#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
map<string,int>mp;
int n,m,cnt,tot,A[maxn],head[maxn],fa[maxn],nxt[maxn],to[maxn];
int dp[maxn][maxn];
inline void Add(int u,int v)
{
	to[++cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
}
int dfs(int now)
{
	dp[now][0]=0;int num=1;
	for(int i=head[now];~i;i=nxt[i])
	{
		int nxt=to[i];num+=dfs(nxt);
		for(int j=num;~j;--j)
			for(int k=1;k<=j;++k)
				dp[now][j]=min(dp[now][j],dp[now][j-k]+dp[nxt][k]);
	}
	dp[now][num]=min(dp[now][num],A[now]);
	return num;
}
int main()
{
	while(scanf("%d%d\n",&n,&m))
	{
		string s;tot=cnt=0;mp.clear();
		memset(head,-1,sizeof head);
		memset(dp,0x3f,sizeof dp);
		memset(fa,0,sizeof fa);
		for(int i=1,u,v;i<=n;++i)
		{
			getline(cin,s);
			stringstream ss(s);ss>>s;
			if(!mp[s])mp[s]=++tot;
			u=mp[s];ss>>A[u];
			while(ss>>s)
			{
				if(!mp[s])mp[s]=++tot;
				v=mp[s];Add(u,v);fa[v]=u;
			}
		}
		for(int i=1;i<=tot;++i)
			if(!fa[i])Add(0,i);
		dfs(0);int ans=0x3f3f3f3f;
		for(int i=m;i<=n;++i)
			if(dp[0][i]<ans)ans=dp[0][i];
		printf("%d\n",ans);
	}
}