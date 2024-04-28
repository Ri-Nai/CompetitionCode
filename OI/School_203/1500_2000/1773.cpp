#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=2e3+5;
int n,A[maxn];vector<int>E[maxn];
bitset<maxm>L[maxn],R[maxn];
bool cmp(int _,int __){return A[_]<A[__];}
void dfs(int u)
{
	L[u].set(A[u]);R[u].set(A[u]);
	int len=E[u].size();
	for(int i=0;i<len;++i)
	{
		int &v=E[u][i];dfs(v);
		if(A[v]<=A[u])continue;
		if((R[u]&(L[v]>>1)).any())R[u]|=R[v];
	}
	for(int i=len-1;i>=0;--i)
	{
		int &v=E[u][i];
		if(A[v]>=A[u])continue;
		if((L[u]&(R[v]<<1)).any())L[u]|=L[v];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,x,y;i<n;++i)
		scanf("%d%d",&x,&y),E[x].push_back(y);
	for(int i=1;i<=n;++i)
		if(!E[i].empty())sort(E[i].begin(),E[i].end(),cmp);
	dfs(1);printf("%lld\n",1ll*L[1].count()*R[1].count());
}