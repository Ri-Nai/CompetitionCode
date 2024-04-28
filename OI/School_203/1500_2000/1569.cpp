#include<bits/stdc++.h>
using namespace std;
int n,m,k;
double A[105][105],B[105];
int main()
{
	scanf("%d%d%d",&n,&m,&k);double w;
	for(int i=1,u;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d%lf",&u,&w),B[u]=max(B[u],w);
	sort(B+1,B+n+1);double ans=0;
	for(int i=n;i>=n-k+1;--i)ans+=B[i];
	printf("%.1f\n",ans);
}