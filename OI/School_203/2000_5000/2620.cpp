#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,W,lw,ww,rw,A[N],num,cnt;
int nL[N],to[N],RnL[N],bz[25][N];//需要多少行,能到达哪里
long long sum[N];
void move(int i,int *nL)
{
	if(num+A[i]<=W)nL[i]=cnt,num+=A[i]+1;
	else num=A[i]+1,nL[i]=++cnt;
}
void solve()
{
	scanf("%d%d%d%d",&n,&W,&ww,&lw);
	rw=W-lw-ww;memset(to,0,sizeof to);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),sum[i]=1+sum[i-1]+A[i];
	num=0;cnt=1;for(int i=1;i<=n;++i)move(i,nL);
	num=0;cnt=1;for(int i=n;i>=1;--i)move(i,RnL);
	for(int i=1;i<=n;++i)to[nL[i]]=i;
	for(int i=1;i<=n;++i)
	{
		int now=i;
		now=upper_bound(sum+now,sum+n+1,sum[now-1]+lw+1)-sum;
		now=upper_bound(sum+now,sum+n+1,sum[now-1]+rw+1)-sum;
		if(now==n+1)now=0;
		bz[0][i]=now;
	}
	for(int i=1;i<=20;++i)
		for(int j=1;j<=n;++j)
			bz[i][j]=bz[i-1][bz[i-1][j]];
	int Q;scanf("%d",&Q);
	for(int h,x;Q--;)
	{
		scanf("%d%d",&x,&h);
		if(x-1&&to[x-1]==0)
		{
			printf("%d\n",nL[n]+h);
			continue;
		}
		int now=to[x-1]+1;
		for(int i=0;i<=20;++i)
			if(1<<i&h)now=bz[i][now];
		if(!now)printf("%d\n",x-1+h);
		else printf("%d\n",x-1+h+RnL[now]);
	}
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}