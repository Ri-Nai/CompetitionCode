#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
const int mod=5557;
char s[10];
int n,m,K,S[55][55],mark[256],ans[55],T;
void Add(int &x,int y)
{
	y<mod||(y%=mod);
	x+=y;
	x>=0||(x+=mod);
	x<mod||(x-=mod);
}
struct Matrix
{
	int M[55][55];
	Matrix(){memset(M,0,sizeof M);}
	Matrix operator *(const Matrix &_)const
	{
		Matrix A;
		FOR(k,1,K)FOR(i,1,K)FOR(j,1,K)
			Add(A.M[i][j],M[i][k]*_.M[k][j]);
		return A;
	}
};
int Qpow(Matrix _,int p)
{
	Matrix res;bool flag=0;
	for(;p;p>>=1,_=_*_)
		if(p&1)if(!flag)res=_,flag=1;
		else res=res*_;
	return res.M[1][K];
}
void solve(int state)
{
	Matrix Base;
	Base.M[1][K]=Base.M[K][K]=1;
	FOR(u,1,n)FOR(v,1,n)
		if(S[u][v])
		{
			Base.M[u][v]=1;
			if((S[u][v]&state)==S[u][v])
				Base.M[u][u+n]=Base.M[u+n][v]=1;
		}
	ans[state]=Qpow(Base,T+1);
}
int pd(int s)
{
	int f=1;
	while(s)f=(s&1)?-f:f,s>>=1;
	return f;
}
int main()
{
	scanf("%d%d",&n,&m);K=n<<1|1;
	mark['B']=1;mark['J']=2;
	mark['M']=4;mark['P']=8;
	FOR(i,1,m)
	{
		int u,v;scanf("%d %d %s",&u,&v,s+1);
		FOR(j,1,strlen(s+1))S[u][v]|=mark[s[j]];
	}
	scanf("%d",&T);
	FOR(i,0,15)solve(i);
	FOR(i,0,14)Add(ans[15],pd(i)*ans[i]);
	printf("%d\n",ans[15]);
}