#include<cstdio>
#include<cstring>
#define Fas
const int maxn=1e5+5;
int n,a[maxn][15],f[maxn][15],t,ans;
inline int max(const int &a,const int &b)
{
	return a>b?a:b;
}
inline int abs(const int &a)
{
	return a>0?a:-a;
}
void solve()
{
	scanf("%d",&n);
	memset(f,-0x3f,sizeof(f));
	for(int i=1,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),
		++a[v][u+1],t=max(t,v);
	f[0][6]=0;
	for(int i=1;i<=t;++i)
		for(int j=1;j<=11;++j)
			if(abs(6-j)<=i)
				f[i][j]=max(max(f[i-1][j-1],f[i-1][j]),f[i-1][j+1])+a[i][j];
	for(int i=1;i<=11;++i)
		ans=max(f[t][i],ans);
	printf("%d\n",ans);
}
int main()
{
	#ifndef F
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);	
}
