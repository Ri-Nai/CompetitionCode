#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=4e5+5;
int head[N],nxt[M],to[M],id[M],in[N],ing[N],tot;
int n,m,val[N];bool mark[M],lqr,flag,ans[N];
inline void Add(int u,int v)
{
	nxt[++tot]=head[u];
	head[u]=tot;to[tot]=v;
	id[tot]=((tot-1)>>1)+1;++ing[v];//ing是虚的
}
void dfs(int u)
{
	for(int &i=head[u];i;i=nxt[i])//删边
	{
		if(mark[id[i]])continue;
		int now=id[i];
		int v=to[i];mark[now]=1;
		dfs(v);ans[now]=(lqr^=1);//01交替染色
		val[u]|=1<<lqr;val[v]|=1<<lqr;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),
		Add(u,v),Add(v,u);
	memcpy(in,ing,sizeof in);//copy一份真正的度
	for(int i=1;i<=n;++i)if(ing[i]&1)Add(0,i),Add(i,0);
	for(int i=0;i<=n;++i)if(ing[i]>=4)dfs(i);//如果度>=4,必定是在两个以上的欧拉回路中
	for(int i=0;i<=n;++i)if(ing[i]==2)dfs(i);//如果度为0,则肯定是在闭环上
	for(int i=1;i<=n;++i)
		if(in[i]>=2&&val[i]!=3&&(flag=1))break;
	if(flag)puts("0");
	else for(int i=1;i<=m;++i)printf("%d\n",2-ans[i]);
}