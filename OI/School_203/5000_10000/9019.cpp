#include<bits/stdc++.h>
using namespace std;
#define ID(x,y) ((x-1)*m+y)
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
const int N=35;
int n=5,m=6,K=30,tot,dx[]={0,1,0,-1,0},dy[]={0,0,1,0,-1},ans[N];
bitset<N>A[N];
int Get()
{
	char c;
	do c=getchar();while(!isdigit(c));
	return c^48^1;
}
void init(int x,int y,int d)
{
	int xx=x+dx[d],yy=y+dy[d];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m)A[ID(x,y)][ID(xx,yy)]=1;
}
int main()
{
	FOR(i,1,n)FOR(j,1,m)A[ID(i,j)][K+1]=Get();
	FOR(i,1,n)FOR(j,1,m)FOR(k,0,4)init(i,j,k);
	FOR(i,1,K)
	{
		if(!A[i][i])FOR(j,i+1,K)if(A[j][i]){swap(A[j],A[i]);break;}
		FOR(j,1,K)if(i!=j&&A[j][i])A[j]^=A[i];
	}
	FOR(i,1,K)if(ans[i]=A[i][K+1])++tot;
	printf("%d\n",tot);
	FOR(i,1,n)FOR(j,1,m)if(ans[ID(i,j)])printf("%d %d\n",i,j);
}