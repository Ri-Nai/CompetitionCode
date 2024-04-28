#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,mod=1e9+7;
char s[N][N];
int n,m,pw[N*N]={1},ans,tot;
inline void Add(int &x,int y)
{
	(x+=y)>=mod&&(x-=mod);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1; j<=m; ++j)
			tot+=s[i][j]=='.';
	}
	for(int i=1,i_=n*m; i<=i_; ++i)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(s[i][j]=='#')continue;
			int now=1;
			while(j+now<=m&&s[i][j+now]=='.')++now;
			Add(ans,1ll*now*pw[tot-now]%mod);
			j+=now;
		}
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
		{
			if(s[j][i]=='#')continue;
			int now=1;
			while(j+now<=n&&s[j+now][i]=='.')++now;
			Add(ans,1ll*now*pw[tot-now]%mod);
			j+=now;
		}
	cout<<ans<<endl;
}
