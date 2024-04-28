#include<bits/stdc++.h>
using namespace std;
int n,m,L,sum[1005][1005],mx,X1,X2,Y1,Y2;
char s[1005][1005];
int main()
{
	scanf("%d%d%d",&n,&m,&L);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			while(s[i][j]!='*'&&s[i][j]!='.')s[i][j]=getchar();
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if(s[i][j]=='*')++sum[i][j];
		}
	}
	for(int i=1;i<=n-L+1;++i)
		for(int j=1;j<=m-L+1;++j)
		{
			const int &tmp=sum[i+L-2][j+L-2]+sum[i][j]-sum[i][j+L-2]-sum[i+L-2][j];
			if(tmp>mx)mx=tmp,X1=i,Y1=j,X2=i+L-1,Y2=j+L-1;
		}
	printf("%d\n",mx);
	for(int i=X1+1;i<X2;++i)
		s[i][Y1]=s[i][Y2]='|';
	for(int i=Y1+1;i<Y2;++i)
		s[X1][i]=s[X2][i]='-';
	s[X1][Y1]=s[X2][Y1]=s[X2][Y2]=s[X1][Y2]='+';
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			putchar(s[i][j]);
		putchar('\n');
	}
}