#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
const int M=505;
int n,m,T,X,Y=M,S[26][M][M],sum,ans,mxn,mnn=M,mxm,mnm=M;//四个端点
char s[M][M];
struct Pnts
{
	int x,y;
	void read()
	{
		scanf("%d%d",&y,&x);
		if(x>mxn)mxn=x;
		else if(x<mnn)mnn=x;
		if(y>mxm)mxm=y;
		else if(y<mnm)mnm=y;
	}
}P[M];
int Cnt(int r,int c,int id)
{
	int res=0;
	FOR(i,1,T)if(P[i].y!=P[i-1].y)
		res+=S[id][r+P[i].x][c+P[i-1].y]-S[id][r+P[i].x][c+P[i].y];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",s[i]+1);
	FOR(i,1,n)FOR(j,1,m)
	{
		FOR(k,0,25)
			S[k][i][j]=S[k][i][j-1]+S[k][i-1][j]-S[k][i-1][j-1];
		++S[s[i][j]-'a'][i][j];
	}
	scanf("%d",&T);
	FOR(i,1,T)P[i].read();P[0]=P[T];
	FOR(i,0,T)P[i].x-=mnn,P[i].y-=mnm;
	mxn-=mnn;mxm-=mnm;
	FOR(i,1,T)if(P[i].y!=P[i-1].y)
		sum+=(P[i-1].y-P[i].y)*P[i].x;
	FOR(i,1,T)if(P[i].x==0&&P[i].y<Y)Y=P[i].y;
	FOR(i,0,n-mxn)FOR(j,0,m-mxm)
	{
		int id=s[X+i+1][Y+j+1]-'a';
		if(sum==Cnt(i,j,id))++ans;
	}
	printf("%d\n",ans);
}