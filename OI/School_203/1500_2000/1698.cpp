#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
#define DOR(i,a,b) for(int i=a,i##_=b;i>=i##_;--i)
const int mod=1e9+7,N=5e4+5;
char s2[N],s1[N];
int m,n,dp[10][N],pw[N],ans,Lsum[N],Rsum[N];
void init()
{
	m=strlen(s2+1);n=strlen(s1+1);pw[0]=1;
	FOR(i,1,n)pw[i]=10ll*pw[i-1]%mod;
	FOR(i,1,n)s1[i]^=48;
	FOR(i,1,m)s2[i]^=48;
	DOR(i,m,1)if(!s2[i])s2[i]=9;else{--s2[i];break;}
	if(s2[1]==0){FOR(i,1,m-1)s2[i]=s2[i+1];s2[m--]=0;}
	FOR(i,1,n>>1)swap(s1[i],s1[n-i+1]);
	FOR(i,1,m>>1)swap(s2[i],s2[m-i+1]);
}
void solve(char *s,int p)
{
	FOR(i,1,n)Lsum[i]=(01ll*Lsum[i-1]+1ll*pw[i-1]*s[i])%mod;
	DOR(i,n,2)Rsum[i]=(10ll*Rsum[i+1]+s[i])%mod;
	FOR(i,2,n)Rsum[i]=(01ll*Rsum[i]*pw[i-2])%mod;
	//预处理出左右的方案数
	FOR(i,1,n)FOR(j,0,9)
	{
		int &x=dp[j][i];
		if(j<s[i]) x=(x+1ll*p*(Rsum[i+1]+pw[i-1]))%mod;
		if(j==s[i])x=(x+1ll*p*(Rsum[i+1]+Lsum[i-1]+1))%mod;
		if(j>s[i]) x=(x+1ll*p*(Rsum[i+1]))%mod;
		x<0&&(x+=mod);
	}
}
int main()
{
	scanf("%s %s",s2+1,s1+1);init();
	solve(s2,-1);solve(s1,1);
	FOR(i,1,n)FOR(j,0,8)FOR(k,j+1,9)
		ans=(ans+(1ll*(k-j)*(1ll*dp[j][i]*dp[k][i]%mod)%mod))%mod;
	ans=(ans<<1)%mod;
	printf("%d\n",ans);
}
/*
算出某一位上出现的某个数字的可能次数
每一位for过去求最终答案
O(100*N)  勉强能冲
但是怎么求某个数字的可能次数呢
+-------+
|爷不知道|
+-------+
*/