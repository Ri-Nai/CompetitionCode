#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+5;
int A[N],B[N],ans[N],n,m;
int main()
{
	scanf("%d",&n);m=1<<n;
	for(int i=1;i<=m;++i)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+m+1);
	for(int i=1;i<=m;++i)A[i]=upper_bound(B+1,B+m+1,A[i])-B-1;
	for(int i=1;i<=m;++i)
	{
		// Rn_1(A[i]);
		int now=A[i];
		if(now==1)ans[i]=n;
		else ans[i]=n-floor(log2(now));
		printf("%d ",ans[i]);
	}
}