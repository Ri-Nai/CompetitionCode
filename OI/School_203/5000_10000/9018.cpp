#include<bits/stdc++.h>
using namespace std;
const int N=505,M=N<<1;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
int n,m;double A[M][N];
bool not0(double p){return p<-1e-6||p>1e-6;}
int main()
{
	scanf("%d%d",&n,&m);
	FOR(i,1,m)FOR(j,1,n+1)scanf("%lf",&A[i][j]);
	FOR(i,1,n)
	{
		FOR(j,i+1,m)if(A[j][i]>A[i][i])swap(A[j],A[i]);
		if(!not0(A[i][i]))continue;
		FOR(j,1,m)
		{
			if(j==i)continue;
			double p=A[j][i]/A[i][i];
			FOR(k,i,n+1)A[j][k]-=A[i][k]*p;
		}
	}
	FOR(i,1,n)if(!not0(A[i][i]))
		if(!not0(A[i][n+1]))return puts("Many solutions"),0;
		else return puts("No solutions"),0;
	FOR(i,1,n)A[i][n+1]/=A[i][i];
	FOR(i,n+1,m)if(not0(A[i][n+1]))return puts("No solutions"),0;
	FOR(i,1,n)printf("%.0f\n",A[i][n+1]);
}