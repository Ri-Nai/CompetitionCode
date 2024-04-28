#include<bits/stdc++.h>
using namespace std;
const int N=605;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=b;++i)
char s[N>>1];int n,sum[N][N],A[N][N],ans;
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)
	{
		scanf("%s",s+1);
		FOR(j,1,n)A[i+j-1][i-j+n]=s[j]=='*';
		//将曼哈顿距离转化成切比雪夫距离
		//(|x1-x2|,|y1-y2|)相当于一个正方形的同侧二顶点与对面边的任意一点形成的三角形
	}n<<=1;
	FOR(i,1,n)FOR(j,1,n)sum[i][j]=sum[i][j-1]+A[i][j];
	FOR(i,1,n)FOR(j,1,n)if(A[i][j])FOR(k,j+1,n)if(A[i][k])
	{
		int dis=k-j,k1=i-dis,k2=i+dis;
		if(k1>=1)ans+=sum[k1][k]-sum[k1][j-1];
		if(k2<=n)ans+=sum[k2][k]-sum[k2][j-1];
	}
	FOR(i,1,n)FOR(j,1,n)sum[i][j]=sum[i-1][j]+A[i][j];
	FOR(i,1,n)FOR(j,1,n)if(A[j][i])FOR(k,j+1,n)if(A[k][i])
	{
		int dis=k-j,k1=i-dis,k2=i+dis;
		if(k1>=1)ans+=sum[k-1][k1]-sum[j][k1];
		if(k2<=n)ans+=sum[k-1][k2]-sum[j][k2];
		//因为之前已经把正方形的四个顶点算过,故不算k和j
	}
	printf("%d\n",ans);
}
/*
咦,我都在学校,应该不可能登录的吧,可能只是YJ更新了或者服务器网络不稳定
有五六个好友是同学吧,还有几个没怎么上线的就应该是退坑了的
*/