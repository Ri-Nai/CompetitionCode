#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
int a,b;
LL f[(int)1e6+5],ans=1;
int main()
{
	scanf("%d%d",&a,&b);f[0]=1;
	for(int i=1;i<=a;++i)f[i]=f[i-1]*26%mod;
	for(int i=2;i<=a;++i)f[i]=(f[i-1]+f[i])%mod;
	for(int i=1;i<=b;++i)ans=ans*f[a]%mod;
	printf("%lld\n",ans);
}