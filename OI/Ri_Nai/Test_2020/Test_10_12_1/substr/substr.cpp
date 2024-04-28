#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,base=19260817,mod=1e9+7;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
typedef unsigned long long ULL;
ULL hsh,now,pw=1;
char S[N],T[N];
int n,m,dp[N],f[N],ans;
void Add(int &x,int y)
{
	// y>=mod &&(y-=mod);
	// (x+=y)>=mod&&(x-=mod);
	x=(1ll*x+y)%mod;
}
int main()
{
//	FILE("substr");
	scanf("%s%s",S+1,T+1);
	n=strlen(S+1); m=strlen(T+1);
	for(int i=1; i<=m; ++i)pw=pw*base,hsh=hsh*base+T[i];
	for(int i=1; i<=n; ++i)
	{
		now=now*base+S[i];
		if(i>m)now-=S[i-m]*pw;
		if(i>=m&&now==hsh)Add(dp[i],f[i-m]+i-m+1);
		else dp[i]=dp[i-1];
		Add(ans,dp[i]);
		Add(f[i],f[i-1]+ans);
	}
	printf("%d\n",ans);
	FCLS();
}
/*
hash判串是否相同
如果相同则继承子串前面部分的答案
否则继承上一份答案
welcometoroundtwohundredandeightytwo
d

*/
