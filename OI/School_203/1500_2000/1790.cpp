#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
map<int,LL>mp[N];
int n,U[N],V[N],W[N],fa[N],dis[N],A[N];
LL ans[N];
int find(int u)
{
	if(u!=fa[u])
	{
		int t=fa[u];
		fa[u]=find(t);
		dis[u]^=dis[t];
	}
	return fa[u];
}
LL Merge(int u,int v,int w)
{
	int fu=find(u),fv=find(v);LL res=0;
	if(mp[fu].size()>mp[fv].size())swap(fv,fu);
	fa[fu]=fv;dis[fu]^=dis[u]^dis[v]^w;
	for(map<int,LL>::iterator it=mp[fu].begin();it!=mp[fu].end();++it)
	{
		const int &tmp=it->first^dis[fu];
		res+=it->second*mp[fv][tmp];
		mp[fv][tmp]+=it->second;
	}
	mp[fu].clear();
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)mp[i][0]=1,fa[i]=i;
	for(int i=1;i<n;++i)scanf("%d%d%d",U+i,V+i,W+i);
	for(int i=1;i<n;++i)scanf("%d",A+i);
	for(int i=n-1;i;--i)ans[i]=ans[i+1]+Merge(U[A[i]],V[A[i]],W[A[i]]);
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);

}