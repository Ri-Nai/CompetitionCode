#include<cstdio>
const int N=2e6+5,mod=998244353;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
int n,m,fact[N]={1},inv[N],ans=0;
int Qpow(int n,int p)
{
	int res=1;
	for(;p;p>>=1,n=1ll*n*n%mod)
		if(p&1)res=1ll*res*n%mod;
	return res;
}
inline int C(int n,int m)
{
	return 1ll*fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int Plan_B()
{
	printf("%d\n",C(n+n-1,n-1));
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);int k=n+(n>m?n:m);
	FOR(i,1,k)fact[i]=1ll*fact[i-1]*i%mod;
	inv[k]=Qpow(fact[k],mod-2);
	for(int i=k-1;~i;--i)inv[i]=1ll*(i+1)*inv[i+1]%mod;
	if(m==0)return Plan_B();
	FOR(i,1,n-1)
		ans=(ans+1ll*C(n-1,i-1)*C(m+n-i-1,n-i-1)%mod*C(n,i)%mod)%mod;
	printf("%d\n",ans);
}
/*
i个装B球,n-i个装W球和空格
n-1 i-1 分别为间隙数和隔板数
保证这些板无重叠
剩下的n-i个可以在m个W球中选择
会有空的箱子出现,所以就是m+n-i-1,n-i-1

一半形成的是关于B球的排列
另一半形成的是关于W球和空格的排列
i箱和n-i箱 我们将这些箱子交叉放入
不妨设i箱插入n-i箱中,可以有板子重叠
也就是n+1个空隙,i个板子
->C(n,i)

考试的时候一直在枚举放W和B球的箱子数
以及计算出空格的个数
但是这样排列的插入会很乱
考试的时候就一直没想出来
*/