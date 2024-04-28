#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=150;
int d,m,n=129,A[N][N],ans;
long long mx,Sum[N][N];
int main()
{
	// FILE("wireless");
	scanf("%d%d",&d,&m);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		scanf("%d",&A[x+1][y+1]);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+A[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int U=max(1,i-d),D=min(n,i+d),
				L=max(1,j-d),R=min(n,j+d);
			long long now=Sum[D][R]-Sum[D][L-1]-Sum[U-1][R]+Sum[U-1][L-1];
			if(now>mx)mx=now,ans=1;
			else if(now==mx)++ans;
		}
	printf("%d %lld\n",ans,mx);
	FCLS();
}