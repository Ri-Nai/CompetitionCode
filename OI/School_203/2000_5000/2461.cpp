#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,nxt[M],to[M],head[N],tot,dp[N],res[N],ans=1,mid;
void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
bool dfs(int u,int f)
{
	multiset<int>S;
	for(int i=head[u],v;v=to[i];i=nxt[i])
	{
		if(v==f)continue;
		if(!dfs(v,u))return 0;
		S.insert(dp[v]+1);
	}
	bool flag=!f;
	if(flag^(S.size()&1^1))S.insert(0);
	while(!S.empty())
	{
		int bt=*S.begin();
		S.erase(S.begin());
		auto et=S.lower_bound(mid-bt);
		if(et==S.end())
		{
			if(flag)return 0;
			else flag=1,dp[u]=bt;
		}
		else S.erase(et);
	}
	if(flag)return 1;
	return 0;
}
int main()
{
	n=rd();int L=1,R=n;
	for(int i=1,u,v;i<n;++i)
		Add(u=rd(),v=rd()),Add(v,u);
	while(L<=R)
	{
		mid=L+R>>1;
		if(dfs(1,0))L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%d\n",ans);
}