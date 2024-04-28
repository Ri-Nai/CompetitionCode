#include<bits/stdc++.h>
using namespace std;
const int M=256;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
int n,m,cnt[M+5][M+5][M+5],sum[M+5][M+5][M+5],R,G,B;
bool check(int T)
{
	FOR(i,T,M)FOR(j,T,M)FOR(k,T,M)
	{
		int now=sum[i][j][k]-sum[i-T][j][k]-sum[i][j-T][k]-sum[i][j][k-T]
		+sum[i-T][j-T][k]+sum[i-T][j][k-T]+sum[i][j-T][k-T]-sum[i-T][j-T][k-T];
		if(now>=m)return R=i,G=j,B=k,1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=n;++i)
		scanf("%d%d%d",&u,&v,&w),++cnt[u+1][v+1][w+1];
	FOR(i,1,M)FOR(j,1,M)FOR(k,1,M)
		sum[i][j][k]=cnt[i][j][k]+sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]
		-sum[i-1][j-1][k]-sum[i-1][j][k-1]-sum[i][j-1][k-1]+sum[i-1][j-1][k-1];
	int l=1,r=M,ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",--ans);
	FOR(i,R-ans,R)FOR(j,G-ans,G)FOR(k,B-ans,B)
	{
		while(cnt[i][j][k]--&&m)
			--m,printf("%d %d %d\n",i-1,j-1,k-1);
		if(!m)break;
	}
}