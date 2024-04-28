#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
int id[25][25],m,n=20;
double p,A[300][300];
void init()
{
	memset(A,0,sizeof A);
	FOR(i,0,n)FOR(j,0,i)
	{
		int u=id[i][j];
		A[u][u]=1;
		if(i==n)continue;
		A[u][m+1]=1;
		A[u][id[i][j+1]]-=p;
		A[u][id[i][max(j-2,0)]]-=1-p;
	}
}
void solve()
{
	FOR(i,1,m)
	{
		FOR(j,i+1,m)
			if(fabs(A[j][i])>fabs(A[i][i]))
				swap(A[j],A[i]);
		FOR(j,1,m)if(i!=j)
		{
			double p=A[j][i]/A[i][i];
			FOR(k,i,m+1)A[j][k]-=A[i][k]*p;
		}
	}
	printf("%f\n",A[1][m+1]/A[1][1]);
}
int main()
{
	FOR(i,0,n)FOR(j,0,i)id[i][j]=id[j][i]=++m;
	while(~scanf("%lf",&p))init(),solve();
}