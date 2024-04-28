#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,C,A[N],sum[N],ans;
int main()
{
	scanf("%d%d",&n,&C);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)
	{
		int now=C,num=0;
		for(int j=i;j<=n;++j)
			if(A[j]<=now)++num,now-=A[j];
		ans=max(ans,num);
	}
	printf("%d\n",ans);
}