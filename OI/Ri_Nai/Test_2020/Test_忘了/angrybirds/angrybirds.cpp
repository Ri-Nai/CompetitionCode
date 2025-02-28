#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=20,M=1<<N-1;
const double eps=1e-7,ppp=1;
int n,m,dp[M],cnt[M],BT[M];
double X[N],Y[N],A[M],B[M];
void show(int p){for(int i=0;i<n;++i)printf("%d",p>>i&1);puts("");}
inline void Get(int i,int j)
{
	int p=1<<i|1<<j;
	double a=X[i]*X[i],b=X[i],c=X[j]*X[j],d=X[j],e=Y[j]/d*b;
	c=c/d*b;
	if(fabs(c-a)<=eps){A[p]=B[p]=ppp,dp[p]=2;return;}
	double k=(e-Y[i])/(c-a);
	if(k>=-eps){A[p]=B[p]=ppp,dp[p]=2;return;}
	A[p]=(e-Y[i])/(c-a);
	B[p]=(Y[i]-A[p]*a)/b;
	dp[p]=1;
}
bool chk(double a,double b,double x,double y)
{
	double tmp=a*x*x+b*x;
	return fabs(tmp-y)<=eps;
}
void Solve()
{
	cin>>n>>m;int k=1<<n;
	for(int i=0;i<n;++i)
		scanf("%lf%lf",&X[i],&Y[i]);
	for(int i=0;i<n;++i)dp[1<<i]=1;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)Get(i,j);
	for(int i=1;i<k;++i)
	{
		if(cnt[i]<=2)continue;
		int p=i&-i,q=BT[p];
		if(A[i^p]!=ppp&&chk(A[i^p],B[i^p],X[q],Y[q]))
			A[i]=A[i^p],B[i]=B[i^p],dp[i]=dp[i^p];
		else
		{
			dp[i]=1e9;A[i]=ppp;
			for(int j=i&i-1;j;j=i&j-1)
			{
				int tmp=dp[j]+dp[i^j];
				dp[i]=min(dp[j]+dp[i^j],dp[i]);
			}
		}
	}
	printf("%d\n",dp[k-1]);
}
int main()
{
	FILE("angrybirds");
	int T;cin>>T;
	for(int i=1;i<M;++i)cnt[i]=cnt[i^i&-i]+1;
	for(int i=0;i<18;++i)BT[1<<i]=i;
	while(T--)Solve();
	FCLS();
}
/*

2
2 0
1.00 3.00
3.00 3.00
5 2
1.00 5.00
2.00 8.00
3.00 9.00
4.00 8.00
5.00 5.00


3
2 0
1.41 2.00
1.73 3.00
3 0
1.11 1.41
2.34 1.79
2.98 1.49
5 0
2.72 2.72
2.72 3.14
3.14 2.72
3.14 3.14
5.00 5.00

1
10 0
7.16 6.28
2.02 0.38
8.33 7.78
7.68 2.09
7.46 7.86
5.77 7.44
8.24 6.72
4.42 5.11
5.42 7.79
8.15 4.99

*/
