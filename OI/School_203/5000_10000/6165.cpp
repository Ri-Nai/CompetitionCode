#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
#define Max(a,b) (a<(b)&&(a=b))
typedef long long ago;
const int N=105;
int n;ago m;
struct Matrix
{
	ago M[N][N];
	Matrix(){memset(M,0,sizeof M);}
	Matrix operator *(const Matrix &_)const
	{
		Matrix res;
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
			if(M[i][k]&&_.M[k][j])Max(res.M[i][j],min(m,M[i][k]+_.M[k][j]));
		return res;
	}
	bool check(){FOR(i,1,n)if(M[1][i]>=m)return 0;return 1;}
}pw[66],now;
void solve()
{
	scanf("%d%lld",&n,&m);
	FOR(i,1,n)FOR(j,1,n)scanf("%lld",&now.M[i][j]);
	pw[0]=now;ago ans=0;
	FOR(i,1,60)pw[i]=pw[i-1]*pw[i-1];
	for(int i=60;~i;--i)
	{
		Matrix tmp=now*pw[i];
		if(tmp.check())
			now=tmp,ans|=1ll<<i;
	}
	printf("%lld\n",ans+2);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}