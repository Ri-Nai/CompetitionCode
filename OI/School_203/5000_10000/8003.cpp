#include<cmath>
#include<cstdio>
#include<algorithm>
const int maxn=3e5+5;
int n,m,fa[20][maxn],ans[maxn],cnt[maxn],a,c;
long long bz[20][maxn],v,K[20][maxn],B[20][maxn],s;
void in_put()
{
	scanf("%d%d",&n,&m);K[0][1]=1;
	for(int i=1;i<=n;++i)scanf("%lld",&bz[0][i]);
	for(int i=2;i<=n;++i)
	{
		scanf("%d%d%lld",&fa[0][i],&a,&v);
		if(a)K[0][i]=v,B[0][i]=0;
		else K[0][i]=1,B[0][i]=v;
	}
	for(int i=0;i<20;++i)K[i][0]=1,bz[i][0]=4e18;
	for(int i=1;i<20;++i)
		for(int j=0;j<=n;++j)
		{
			int from=fa[i-1][j];
			long long tmp=ceil(1.0*(bz[i-1][from]-B[i-1][j])/K[i-1][j]);
			fa[i][j]=fa[i-1][from];
			bz[i][j]=std::max(bz[i-1][j],tmp);
			B[i][j]=B[i-1][j]*K[i-1][from]+B[i-1][from];
			K[i][j]=K[i-1][j]*K[i-1][from];
		}
}
int main()
{
	in_put();
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%d",&s,&c);
		for(int j=19;j>=0;--j)
			if(s>=bz[j][c])
				s=s*K[j][c]+B[j][c],c=fa[j][c],cnt[i]+=1<<j;
		++ans[c];
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	for(int i=1;i<=m;++i)printf("%d\n",cnt[i]);
}