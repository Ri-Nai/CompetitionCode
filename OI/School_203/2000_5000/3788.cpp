#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int L[maxn],R[maxn],to[maxn],tot;
int n,S,dep[maxn],num,cnt,Time[maxn],dfn[maxn<<4];
bool mark[maxn],fst[maxn<<4],vis[maxn];
int read()
{
	int t=0,c;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
void dfs(int now,int f)
{
	dep[now]=dep[f]+1;
	dfn[++num]=now;fst[num]=1;
	if(S==now)mark[now]=1;
	for(int i=L[now]+1;i<=R[now];++i)
	{
		int v=to[i];dfs(v,now);
		dfn[++num]=now;fst[num]=0;
		mark[now]|=mark[v];
	}
	if(mark[now])Time[now]=cnt++;
}
void solve()
{
	n=read();cnt=num=tot=0;
	memset(mark,0,sizeof mark);
	memset(vis ,0,sizeof vis );
	for(int i=1,k,x;i<=n;++i)
	{
		k=read();L[i]=tot;
		for(int j=1;j<=k;++j)
			x=read(),to[++tot]=x;
		R[i]=tot;
	}
	S=read();dfs(1,0);int ans=0;
	for(int i=1;i<=num;++i)
	{
		int u=dfn[i];
		if(mark[u]&&i-Time[u]>0&&fst[i-Time[u]])
		{
			int v=dfn[i-Time[u]];
			if(mark[v]&&dep[v]<=dep[u]&&!vis[v])
				++ans,vis[v]=1;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int T=read();
	while(T--)solve();
}