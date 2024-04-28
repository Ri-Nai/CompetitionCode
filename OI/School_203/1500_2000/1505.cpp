#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=6e5+5;
typedef long long Ago;
typedef pair<Ago,int>pr;
#define LW(x) x=lower_bound(C+1,C+len+1,x)-C
int nxt[M],to[M],head[N],tot,len,m;
Ago n,A[N],B[N],C[N],W[M],dis[N];
bool vis[N];
Ago rd()
{
	Ago t=0;int c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
Ago Get(Ago x)
{
	Ago k=sqrt(x);
	if(k*k!=x)++k;
	Ago tot=k*k;
	if(tot-x<k)return x-4*k+5;
	return x-4*k+7;
}

void Add(int u,int v,Ago w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
Ago Dijkstra()
{
	memset(dis,0x3f,sizeof dis);
	priority_queue<pr,vector<pr>,greater<pr>>Q;
	LW(n);Q.push(pr(dis[1]=0,1));
	while(!Q.empty())
	{
		int u=Q.top().second;
		Q.pop();if(vis[u])continue;
		if(u==n)return dis[u];vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];Ago w=W[i];
			if(dis[v]>dis[u]+w)
				Q.push(pr(dis[v]=dis[u]+w,v));
		}

	}
}
int main()
{
	n=rd();m=rd();C[++len]=n;C[++len]=1;
	for(int i=1;i<=m;++i)C[++len]=B[i]=Get(C[++len]=A[i]=rd());
	sort(C+1,C+len+1);len=unique(C+1,C+len+1)-C-1;
	for(int i=1;i<=m;++i)Add(LW(A[i]),LW(B[i]),1),Add(B[i],A[i],1);
	for(int i=1;i<len;++i)Add(i,i+1,C[i+1]-C[i]),Add(i+1,i,C[i+1]-C[i]);
	printf("%lld\n",Dijkstra());
}
