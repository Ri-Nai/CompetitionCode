#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5,mod=1e9+7;
int n,K,head[N],to[N],nxt[N],in[N],tot;
LL dp[N],ans=1;
queue<int>Q;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	++in[v];
}
void init()
{
	dp[1]=K;dp[2]=1ll*K*(K-1)%mod;
	dp[3]=1ll*K*(K-1)%mod*(K-2)%mod;
	for(int i=4;i<=n;++i)
		dp[i]=(dp[i-1]*(K-2)+dp[i-2]*(K-1))%mod;
}
void solve(int f)
{
	--in[f];int sz=1;
	for(int u=f,v;(v=to[head[u]])!=f;u=v,++sz,--in[v]);
	ans=ans*dp[sz]%mod;
}
int main()
{
	scanf("%d%d",&n,&K);init();
	for(int i=1,u;i<=n;++i)
		scanf("%d",&u),Add(i,u);
	for(int i=1;i<=n;++i)
		if(in[i]==0)Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		ans=ans*(K-1)%mod;
		for(int i=head[u],v;i;i=nxt[i])
			if(--in[v=to[i]]==0)Q.push(v);
	}
	for(int i=1;i<=n;++i)
		if(in[i])solve(i);
	printf("%lld\n",ans);
}