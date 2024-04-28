#include<cstdio>
#include<queue>
#define mp std::make_pair
#define F
const int maxn=1e5+5;
int cnt[maxn],ans;
std::queue<std::pair<int,int> > q;
void solve()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		while(!q.empty())
		{
			int now=q.front().first;
			int from=q.front().second;
			if(n-now>=86400)
			{
				q.pop();
				--cnt[from];
				if(cnt[from]==0)
					--ans;
			}
			else break;
		}
		for(int i=1,now;i<=m;++i)
		{
			scanf("%d",&now);
			if(cnt[now]==0)++ans;
			++cnt[now];
			q.push(mp(n,now));
		}
		printf("%d\n",ans);
	}
}
int main()
{
	#ifndef F
	freopen("port.in","r",stdin);
	freopen("port.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
