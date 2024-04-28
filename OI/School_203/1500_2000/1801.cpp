#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
int n,pw[405],cnt[25][25],ans;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	scanf("%d",&n);pw[0]=1;
	for(int i=1;i<=400;++i)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
	for(int k=i;k<=j;++k)
	for(int l=k+1;l<=j;++l)
		cnt[i][j]+=gcd(k,l)==1;
	for(int i=0;i<(1<<n-1);++i)
	{
		int num=0,res=1,last=1;
		for(int j=1;j<n;++j)
		{
			if(i&1<<j-1)
			{
				++num;
				res=1ll*res*pw[cnt[last][j]]%mod,last=j+1;
			}
		}
		res=1ll*res*pw[cnt[last][n]]%mod;
		if(num&1)ans=((ans-res)%mod+mod)%mod;
		else ans=(ans+res)%mod;
	}
	printf("%d\n",ans);
}
/*







 int prev = 1, curr = 1;
    for (int x = 1; x < n; ++x)
      if (mask & (1 << (x - 1))) {
	curr = (llint)curr * p2[tot[prev][x]] % MOD;
	prev = x + 1;
      }
    curr = (llint)curr * p2[tot[prev][n]] % MOD;
    res += __builtin_popcount(mask) % 2 == 0 ? curr : -curr;
    res %= MOD;
  } 
*/