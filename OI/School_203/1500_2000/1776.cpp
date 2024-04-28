#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=N*N>>1;
priority_queue<int>Q;
int n,nxt[M],to[M],head[N],in[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;head[u]=tot;
	++in[v];
}
struct $
{
	int x1,y1,x2,y2;
	double k,b;
	void read()
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1^x2)
			k=(y1-y2)/1.0/(x1-x2);
		else k=0;
		b=1.0*y1-1.0*k*x1;
		if(x1>x2)swap(x1,x2),swap(y1,y2);
	}
}P[N];
inline bool cmp(double d1,double d2)
{
	return d1<(d2+1e-6);
}
inline bool check(int i,int j)
{
	if(P[j].x1>P[i].x2||P[j].x2<P[i].x1)return 0;
	if(P[j].x1<=P[i].x1)return cmp(P[j].k*P[i].x1+P[j].b,1.0*P[i].y1);
	if(P[j].x2>=P[i].x2)return cmp(P[j].k*P[i].x2+P[j].b,1.0*P[i].y2);
	return cmp(1.0*P[j].y1,P[i].k*P[j].x1+P[i].b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)P[i].read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j==i)continue;
			if(check(i,j))Add(j,i);
		}
		if(!in[i])Q.push(i);
	}
	while(!Q.empty())
	{
		int now=Q.top();
		Q.pop();
		printf("%d ",now);
		for(int i=head[now];i;i=nxt[i])
			if(--in[to[i]]==0)Q.push(to[i]);
	}
}