#include<bits/stdc++.h>
using namespace std;
typedef set<int>::iterator st;
const int N=5e5+5;
set<int>S;int n,A[N],B[N],mn=1e9,pos,ans;
int nxt[N],to[N],head[N],sz[N],tot;
void Add(int u,int v)
{
	++sz[u];nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u;i<=n;++i)
		scanf("%d",&u),Add(u,i);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)scanf("%d",&B[i]);
	for(int i=1,now=0;i<=n;++i)
	{
		now+=sz[i]-1;
		if(now<mn)mn=now,pos=i;
	}pos=pos%n+1;
	for(int i=1;i<=n;++i)
	{
		for(int j=head[pos];j;j=nxt[j])S.insert(B[to[j]]);
		st it=S.upper_bound(A[pos]);
		if(it!=S.end())++ans,S.erase(it);
		else S.erase(S.begin());
		pos=pos%n+1;
	}
	printf("%d\n",ans);
}