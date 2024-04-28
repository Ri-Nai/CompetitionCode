#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=2005;
int n,m,T,k,fact[N][5],p[5],cnt[5],tot,is[N][N],Sum[N][N];
void solve()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",Sum[n][m]);
}
bool check(int n,int m)
{
	for(int i=1;i<=tot;++i)
	{
		int now=fact[n][i]-fact[n-m][i]-fact[m][i];
		if(now<cnt[i])return 0;
	}
	return 1;
}
void init()
{
	int tmp=k;
	for(int i=2;tmp!=1;++i)
	{
		if(tmp%i==0)
		{
			p[++tot]=i;
			while(tmp%i==0)tmp/=i,++cnt[tot];
		}
	}
	for(int i=1;i<=2000;++i)
		for(int j=1;j<=tot;++j)
		{
			fact[i][j]=fact[i-1][j];
			int tmp=i;
			while(tmp%p[j]==0)++fact[i][j],tmp/=p[j];
		}
	for(int i=1;i<=2000;++i)
		for(int j=1;j<=i;++j)
			is[i][j]=check(i,j);
	for(int i=1;i<=2000;++i)
		for(int j=1;j<=2000;++j)
			Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+is[i][j];
}
int main()
{
	FILE("problem");
	cin>>T>>k;
	init();
	while(T--)solve();
	FCLS();
}
