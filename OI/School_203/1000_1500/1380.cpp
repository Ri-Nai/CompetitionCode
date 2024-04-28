#include<cstdio>
#include<queue>
const int maxn=305;
int n,fa[maxn],tot,ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct $
{
	int u,v,w;
	bool operator <($ _)const{return w>_.w;}
};
std::priority_queue<$>Q;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i)fa[i]=i;
	for(int i=0,w;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&w);
			if(i<j)Q.push(($){j,i,w});
		}
	while(!Q.empty())
	{
		int u=find(Q.top().u),v=find(Q.top().v),w=Q.top().w;
		//int uu=Q.top().u,vv=Q.top().v;
		Q.pop();
		if(u!=v)++tot,fa[v]=u,ans+=w;
		//printf("%d %d %d\n",uu,vv,w);
		if(tot==n)break;
	}
	printf("%d\n",ans);

}