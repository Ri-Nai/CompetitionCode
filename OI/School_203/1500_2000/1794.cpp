#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int A[N],n,k;
long long C[N][55],ans;
void init()
{
	C[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=i&&j<=k;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
int main()
{
	scanf("%d%d",&n,&k);init();
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
		(ans+=A[i]*C[i-1][k-1]%mod)%=mod;
	printf("%lld\n",ans);
}