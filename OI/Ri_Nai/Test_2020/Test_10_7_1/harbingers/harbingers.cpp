#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5,M=N<<1;
typedef long long LL;
LL Y[N],X[N],fw[N];
int n,S[N],V[N],tp,Stk[N];
int nxt[M],to[M],W[M],head[N],tot;
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
void predfs(int u,int f)
{
	fw[u]=X[u]*V[u]+S[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i],w=W[i];
		if(v==f)continue;
		X[v]=X[u]+w;
		predfs(v,u);
	}
}
bool chk(int a,int b,int c)
{
	return 1.*(X[b]-X[a])*(Y[c]-Y[b])>1.*(X[c]-X[b])*(Y[b]-Y[a]);
}
LL Get(int u,int k)
{
	return X[u]*k+Y[u];
}
LL Solve(int k)
{
	int l=1,r=tp,ans=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(mid==1||Get(Stk[mid],k)<Get(Stk[mid-1],k))
			l=mid+1,ans=mid;
		else r=mid-1;
	}
	return Get(Stk[ans],k);
}
int find(int u)
{
	int l=2,r=tp,ans=tp+1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(!chk(Stk[mid-1],Stk[mid],u))
			r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
void dfs(int u,int f)
{
	Y[u]=Solve(-V[u])+fw[u];
	int tmp=tp;tp=find(u);
	int pp=Stk[tp];Stk[tp]=u;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]^f)dfs(to[i],u);
	Stk[tp]=pp,tp=tmp;
}
int main()
{
	n=rd();
	for(int i=1,u,v,w;i<n;++i)
		u=rd(),v=rd(),w=rd(),Add(u,v,w),Add(v,u,w);
	for(int i=2;i<=n;++i)S[i]=rd(),V[i]=rd();
	predfs(1,0);dfs(1,0);
	for(int i=2;i<=n;++i)printf("%lld ",Y[i]);
	puts("");
	FCLS();
}