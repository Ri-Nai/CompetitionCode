#include<bits/stdc++.h>
using namespace std;
#define ID(x,y) ((x-1)*m+(y))
char s[N];
const int N=1e6+5;
int n,m,k,mark[256];
int head[N],to[N],nxt[N],tot;
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	mark['U']=-m;mark['D']=m;
	mark['L']=-1;mark['R']=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)if(j!=m)
			Add(ID(i,j)+mark[s[i]],ID(i,j));
	}
}