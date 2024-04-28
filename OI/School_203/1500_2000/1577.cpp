#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,A[N],C[N],stk[N],top,F[N],in[N],ans;
void solve(int u)
{
	int mn=1e9,now;
	for(int v=F[u];in[v];u=v,v=F[v])
	{
		in[v]=0;now=max(C[v]-A[u],0);
		ans+=now;mn=min(C[v]-now,mn);
	}
	ans+=mn;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&F[i],&A[i]),
		C[i]=A[i],++in[F[i]];
	for(int i=1;i<=n;++i)
		if(!in[i])stk[++top]=i;
	while(top)
	{
		int u=stk[top--];ans+=C[u];
		C[F[u]]=max(0,C[F[u]]-A[u]);
		if(--in[F[u]]==0)stk[++top]=F[u];
	}
	for(int i=1;i<=n;++i)
		if(in[i])solve(i);
	printf("%d\n",ans);
}