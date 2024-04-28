#include<bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
const int N=15,M=125;
int n,m;
double A[M][N],B[N][N];
void Init(int x,int y)
{
	++m;A[m][n+1]=0;
	for(int i=1;i<=n;++i)
		A[m][i]=2.0*(B[x][i]-B[y][i]),
		A[m][n+1]+=sqr(B[x][i])-sqr(B[y][i]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<=n;++j)
			scanf("%lf",&B[i][j]);
	for(int i=1;i<=n+1;++i)
		for(int j=i+1;j<=n+1;++j)
			Init(i,j);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=m;++j)
			if(fabs(A[j][i])>fabs(A[i][i]))swap(A[j],A[i]);
		for(int j=1;j<=m;++j)
		{
			if(j==i)continue;
			long double p=A[j][i]/A[i][i];
			for(int k=i;k<=n+1;++k)
				A[j][k]-=A[i][k]*p;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%.3f ",A[i][n+1]/A[i][i]);
}