#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=45,M=N*N;
int n,m,ps1[M],ps2[M],mp[N][N];
int main()
{
	FILE("magic");
	cin>>n;m=n*n;
	ps1[1]=1;ps2[1]=(n>>1)+1;
	mp[ps1[1]][ps2[1]]=1;
	for(int i=2; i<=m; ++i)
	{
		int x=ps1[i-1],y=ps2[i-1],nx,ny;
		if(x==1&&y!=n)nx=n,ny=y+1;
		else if(y==n&&x!=1)nx=x-1,ny=1;
		else if(x==1&&y==n)nx=2,ny=n;
		else if(x-1>=1&&y+1<=n&&!mp[x-1][y+1])nx=x-1,ny=y+1;
		else nx=x+1,ny=y;
		mp[ps1[i]=nx][ps2[i]=ny]=i;
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=n;++j)
			printf("%d ",mp[i][j]);
	FCLS();
}
