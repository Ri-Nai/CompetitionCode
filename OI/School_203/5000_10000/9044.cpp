#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,k,ans=1e9+5;
int solve(int x,int y)
{
	return (x-y+1)*y;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<=i;++j)
		{
			scanf("%d",&x);
			if(solve(i,j)<=k)ans=min(ans,x);
		}
	printf("%d\n",ans);
}