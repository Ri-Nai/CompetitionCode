#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int A[N],n,cnt,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=n;i>=1;--i)
	{
		if(A[i]!=i+cnt)
			++ans,++cnt;
	}
	printf("%d\n",ans);
}