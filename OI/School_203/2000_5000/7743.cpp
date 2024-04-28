#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=N<<1;
int n,k,A[N];	
int nxt[M],to[M],W[M],head[N];
void Add(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
int main()
{
	cin>>n>>k;
	for(int i=1,u,v,w; i<n; ++i)
		scanf("%d%d%d",&u,&v,&w),Add(u,v,w),Add(v,u,w);
	for(int i=1; i<=k; ++k)scanf("%d",A[i]);
}
