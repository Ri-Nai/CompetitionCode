#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#define F
int n,m,a[1005][1005],in[1005];
std::vector<int> v[1005];
bool mark[1005],pd[1005][1005];
void pre()
{
	scanf("%d%d",&n,&m);
	for(int i=1,len;i<=m;++i)
	{
		scanf("%d",&len);
		memset(mark,0,sizeof(mark));
		for(int j=1;j<=len;++j)
			scanf("%d",&a[i][j]),mark[a[i][j]]=1;
		for(int j=a[i][1];j<=a[i][len];++j)
			if(!mark[j])
				for(int k=1;k<=len;++k)
					if(!pd[j][a[i][k]])
					{
						v[j].push_back(a[i][k]);
						++in[a[i][k]];
						pd[j][a[i][k]]=1;
					}
	}
}
void toposort()
{
	std::queue<std::pair<int,int> > q;
	for(int i=1;i<=n;++i)
		if(!in[i])
			q.push(std::make_pair(i,1));
	int ans=1;
	while(!q.empty())
	{
		int index=q.front().first;
		int level=q.front().second;
		if(level>ans)ans=level;
		q.pop();
		for(int i=0;i<v[index].size();++i)
		{
			--in[v[index][i]];
			if(!in[v[index][i]])
				q.push(std::make_pair(v[index][i],level+1));
		}
	}
	printf("%d\n",ans);
}
void solve()
{
	pre();
	toposort();
}
int main()
{
	#ifndef F
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	#endif 
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
9 2
4 1 3 5 6 
3 5 6 3
9 3
4 1 3 5 6
3 5 6 3
3 1 5 9
*/
