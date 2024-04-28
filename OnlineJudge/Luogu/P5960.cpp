#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,U[N],V[N],W[N],dis[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&V[i],&U[i],&W[i]);
	memset(dis,0x3f,sizeof dis);dis[1]=0;
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			dis[V[j]]=min(dis[U[j]]+W[j],dis[V[j]]);
	for(int i=1;i<=m;++i)
		if(dis[V[i]]>dis[U[i]]+W[i])
			return !puts("NO");
	for(int i=1;i<=n;++i)printf("%d ",dis[i]);
}