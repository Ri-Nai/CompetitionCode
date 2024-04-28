#include<bits/stdc++.h>
using namespace std;
const int maxn=1004;
int n,m,h,sum,A[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;++i)
		scanf("%d",&A[i]),sum+=A[i];
	--n;--sum;--A[h];
	if(sum<n)puts("-1");
	else
	{
		double ans=1;
		for(int i=0;i<n;++i)
			ans*=1.0*(sum-A[h]-i)/(sum-i);
		printf("%.10f\n",1.0-ans);
	}
}