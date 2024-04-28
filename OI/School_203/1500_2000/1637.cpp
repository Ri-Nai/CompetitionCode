#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
const int N=1<<22,M=1e6+5,mod=1e9+7;
int n,m,cnt[N],pw[M]={1},bt[N],ans;
int Mod(int y)
{
	y<0&&(y+=mod);
	y<mod||(y-=mod);
	return y;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int k,x,st=0;m--;st=0)
	{
		scanf("%d",&k);
		while(k--)scanf("%d",&x),st|=(1<<x-1);
		++cnt[st];
	}m=1<<n;
	FOR(i,1,M-5)pw[i]=Mod(pw[i-1]<<1);
	FOR(i,1,m-1)bt[i]=bt[i^(i&-i)]+1;
	FOR(j,0,n-1)FOR(i,1,m-1)
		if(1<<j&i)cnt[i]=Mod(cnt[i]+cnt[i^(1<<j)]);
	FOR(i,0,m-1)
		if((n-bt[i])&1)ans=Mod(ans-pw[cnt[i]]);
		else ans=Mod(ans+pw[cnt[i]]);
	printf("%d\n",ans);
}