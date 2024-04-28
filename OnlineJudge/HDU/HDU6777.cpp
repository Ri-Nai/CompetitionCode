#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn=2e4+5;
struct $
{
	int id,pos;
};
int n,A[maxn];
bool mark[maxn];
std::vector<$>E[105];
void Clear()
{
	for(int i=0;i<105;++i)E[i].clear();
	memset(mark,0,sizeof mark);
}
void solve()
{
	scanf("%d",&n);
	Clear();mark[1]=1;
	for(int i=1,k;i<=n;++i)
	{
		scanf("%d",&k);
		for(int j=1,t,pos;j<=k;++j)
		{
			scanf("%d%d",&t,&pos);
			E[t].push_back(($){i,pos});
			//printf("%d %d %d\n",i,t,pos);
		}
	}
	for(int i=1;i<=100;++i)
	{
		bool p[15]={};
		for(int j=0;j<E[i].size();++j)
		{
			int id=E[i][j].id,pos=E[i][j].pos;
			p[pos]|=mark[id];
		//	printf("%d %d %d %d %d\n",i,id,pos,mark[id],p[pos]);
		}
		for(int j=0;j<E[i].size();++j)
		{
			int id=E[i][j].id,pos=E[i][j].pos;
			mark[id]|=p[pos];
		}
	}
	printf("1");
	for(int i=2;i<=n;++i)
		if(mark[i])printf(" %d",i);
	puts("");
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}