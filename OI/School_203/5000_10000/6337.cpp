#include<bits/stdc++.h>
using namespace std;
typedef double lb;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
#define EOR(i,u) for(int i=head[u],v,w;w=W[i],v=to[i];i=nxt[i])
const int N=105,M=20005;lb A[N][N],ans;
int n,m,head[N],to[M],nxt[M],W[M],tot,deg[N];
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];++deg[v];
	W[tot]=w;to[head[u]=tot]=v;
}
void solve(int BT)
{
	memset(A,0,sizeof A);
	FOR(u,1,n)
	{
		A[u][u]=1;
		if(u!=n)EOR(i,u)
			if(BT&w)A[u][v]+=1.0/deg[u],A[u][n+1]+=1.0/deg[u];
			else A[u][v]-=1.0/deg[u];
	}
	FOR(i,1,n)
	{
		FOR(j,i+1,n)if(fabs(A[j][i])>fabs(A[i][i]))swap(A[i],A[j]);
		FOR(j,1,n)if(i!=j){lb p=A[j][i]/A[i][i];FOR(k,i,n+1)A[j][k]-=A[i][k]*p;}
	}
	ans+=BT*A[1][n+1]/A[1][1];
}
int main()
{
	scanf("%d%d",&n,&m);
	FOR(i,1,m)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);if(u^v)Add(v,u,w);
	}
	FOR(i,0,30)solve(1<<i);printf("%.3f\n",ans);
}