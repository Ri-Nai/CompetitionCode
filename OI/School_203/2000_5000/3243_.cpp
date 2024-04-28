#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+5;LL ans;
int C[N],A[N],sz[N],L[N],R[N],n,tot;
int read()
{
	int now=++tot;
	scanf("%d",&A[now]);
	sz[now]=1;
	if(!A[now])
		L[now]=read(),R[now]=read(),
		sz[now]=sz[L[now]]+sz[R[now]];
	return now;
}
void Add(int x)
{
	while(x<=n)++C[x],x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
LL Cnt(int x)
{
	if(A[x])return Sum(A[x]);
	return Cnt(L[x])+Cnt(R[x]);
}
void dfs(int u)
{
	if(A[u]){Add(A[u]);return;}
	if(sz[L[u]]<sz[R[u]])swap(L[u],R[u]);
	LL res=Cnt(R[u]); dfs(L[u]);
	res=Cnt(R[u])-res;dfs(R[u]);
	ans+=min(res,1ll*sz[L[u]]*sz[R[u]]-res);
}
int main()
{
	scanf("%d",&n);read();dfs(1);
	printf("%lld\n",ans);
}