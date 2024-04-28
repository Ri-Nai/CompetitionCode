#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
const int N=305;int n,ans,mn;
void Min(int &a,int b){a>b&&(a=b);}
int rd()
{
	int t=0,c;do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
struct Matrix
{
	int M[N][N];
	Matrix(){memset(M,0x3f,sizeof M);}
	Matrix operator *(const Matrix &_)const
	{
		Matrix res;
		FOR(i,1,n)FOR(j,1,n)res.M[i][j]=min(M[i][j],_.M[i][j]);
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
			Min(res.M[i][j],M[i][k]+_.M[k][j]);
		return res;
	}
	bool check()
	{
		FOR(i,1,n)if(M[i][i]<0)return 0;
		return 1;
	}
}now,tmp,Fly[10];
void Add()
{
	int u=rd(),v=rd(),w1=rd(),w2=rd();
	now.M[u][v]=w1-w2;
}
int main()
{
	n=rd();FOR(i,1,rd())Add();Fly[0]=now;
	FOR(i,1,8)Fly[i]=Fly[i-1]*Fly[i-1];
	for(int i=8;i>=0;--i)
	{
		tmp=now*Fly[i];
		if(tmp.check())
			ans|=1<<i,now=tmp;
	}
	ans+=2;now=now*Fly[0];
	printf("%d ",ans);
	FOR(i,1,n)Min(mn,now.M[i][i]);
	printf("%d\n",-mn);
}