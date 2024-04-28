#include<cstdio>
#include<vector>
#define F
int n,now,mark[1<<22],sum[1<<22];
long long m,ans;
std::vector<int> frd[25];
void showbit(int p)
{
	puts("");
	for(int i=1;i<=n;++i)
		printf("%d",p&1),
		p>>=1;
	puts("");
}
void solve()
{
	scanf("%d%lld",&n,&m);
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%1d",&x);
			if(i!=j&&x)frd[i].push_back(j);
		}
	long long i;
	int now=0,last,p,from,ed;
	for(i=1;i<=m;++i)
	{
		p=0;
		now=0;
		if(i==1)
			for(int j=0;j<frd[1].size();++j)
				p|=1<<frd[1][j]-1,
				++now;
		else
			for(int j=1;j<=n;++j)
				if((last>>j-1)&1)
					for(int k=0;k<frd[j].size();++k)
						p^=1<<frd[j][k]-1,
						++now;
				else
					now+=frd[j].size()*2;
		showbit(p);
		if(mark[p]&&mark[p]!=1&&mark[p]!=2)
		{
			sum[i]=now;
			from=mark[p];
			ed=i;
			break;
		}
		
		ans+=now;
		last=p;
		mark[p]=i;
		sum[i]=now;
	}
	if(i==m+1)
		printf("%lld\n",ans);
	else
	{
		long long Sum=0;
		for(int i=from;i<ed;++i)
			Sum+=sum[i+1];
		ans-=Sum;
		int len=ed-from;
		m-=from-1;
		ans+=(m/len)*1LL*Sum;
		for(int i=from,j=0;j<m%len;++i,++j)
			ans+=sum[i];
		printf("%lld\n",ans);
		
	}
}
int main()
{
	#ifndef F
	freopen("lubenica.in","r",stdin);
	freopen("lubenica.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
/*
5 3
01000
10110
01000
01001
00010

10 450
0100000000
1011000000
0100110000
0100001110
0010000001
0010000001
0001000001
0001000001
0001000001
0000111110
*/
