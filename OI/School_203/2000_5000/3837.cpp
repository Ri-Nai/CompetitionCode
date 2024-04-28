#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3.5e4+5,M=55;
const LL inf=1e18;
int n,m,A[N],pl=1,pr,now,cnt[N];
LL dp[M][N];
void ToMax(LL &x,LL y,int &idx,int idy)
{
	if(y>x)x=y,idx=idy;
}
int Calc(int l,int r)
{
	while(pl>l)now+=!cnt[A[--pl]]++;
	while(pl<l)now-=!--cnt[A[pl++]];
	while(pr<r)now+=!cnt[A[++pr]]++;
	while(pr>r)now-=!--cnt[A[pr--]];
	return now;
}
void Solve(int p,int L,int R,int l,int r)
{
	if(L>R)return ;
	int opt=n+1,mid=L+R>>1;
	LL res=-inf;
	for(int i=l;i<mid&&i<=r;++i)
		ToMax(res,dp[p-1][i]+Calc(i+1,mid),opt,i);
	dp[p][mid]=res;
	Solve(p,L,mid-1,l,opt);
	Solve(p,mid+1,R,opt,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)dp[1][i]=Calc(1,i);
	for(int i=2;i<=m;++i)Solve(i,1,n,0,n);
	printf("%lld\n",dp[m][n]);
}