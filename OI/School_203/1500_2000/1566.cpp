#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
#define DOR(i,a,b) for(int i=a,i##_=b;i>=i##_;--i)
const int N=1005;
int n,U[N][N],D[N][N],LU[N][N],RU[N][N],LD[N][N],RD[N][N];
int mx[N],num[N],top,now;long long SLD[N][N],SLU[N][N],ans;
char s[N][N];
void work(int x)
{
	int cnt=1;
	while(top&&mx[top]>=x)cnt+=num[top],now-=num[top]*mx[top],--top;
	num[++top]=cnt;mx[top]=x;now+=x*cnt;
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)scanf("%s",s[i]+1);
	FOR(i,1,n)FOR(j,1,n)if(s[i][j]=='C')U[i][j]=U[i-1][j]+1;

	DOR(i,n,1)FOR(j,1,n)if(s[i][j]=='C')D[i][j]=D[i+1][j]+1;
	FOR(i,1,n)
	{
		top=now=0;FOR(j,1,n)work(U[i][j]),RD[i][j]=max(now-1,0);
		top=now=0;FOR(j,1,n)work(D[i][j]),RU[i][j]=max(now-1,0);
		top=now=0;DOR(j,n,1)work(U[i][j]),LD[i][j]=max(now-1,0);
		top=now=0;DOR(j,n,1)work(D[i][j]),LU[i][j]=max(now-1,0);
	}
	FOR(i,1,n)DOR(j,n,1)SLD[i][j]=SLD[i-1][j]+SLD[i][j+1]-SLD[i-1][j+1]+LD[i][j];
	DOR(i,n,1)DOR(j,n,1)SLU[i][j]=SLU[i+1][j]+SLU[i][j+1]-SLU[i+1][j+1]+LU[i][j];
	FOR(i,1,n)FOR(j,1,n)
	ans+=(SLU[i+1][1]+SLU[1][j+1]-SLU[i+1][j+1])*RD[i][j]-SLD[i-1][j+1]*RU[i][j];
	printf("%lld\n",ans%10007);
}