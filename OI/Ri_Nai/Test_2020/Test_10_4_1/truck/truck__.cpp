#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5,MQ=3e4+5;
int n,m,q,fa[N],ans[MQ];
int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}
struct Edge
{
	int u,v,w;
	void Union() {fa[find(u)]=find(v);}
	void read() {scanf("%d%d%d",&u,&v,&w);}
	bool operator <(const Edge &_)const {return w>_.w;}
} E[M];
struct Que
{
	int L,R,mid,s,t,id;
	void read(int i)
	{
		L=E[m].w; R=E[1].w;
		mid=L+R>>1; ans[id=i]=-1;
		scanf("%d%d",&s,&t);
	}
	void check(int &now)
	{
		while(now<=m&&E[now].w>=mid)E[now++].Union();
		if(find(s)==find(t))L=mid+1,ans[id]=mid;
		else R=mid-1; mid=L+R>>1;
	}
	bool operator <(const Que &_)const
	{
		return mid>_.mid;
	}
} Q[MQ];
int main()
{
	cin>>n>>m;
	for(int i=1; i<=m; ++i)E[i].read();
	cin>>q; sort(E+1,E+m+1);
	for(int i=1; i<=q; ++i)Q[i].read(i);
	for(int p=1; p<20; ++p)
	{
		for(int i=1; i<=n; ++i)fa[i]=i;
		for(int i=1,now=1; i<=q; ++i)Q[i].check(now);
		sort(Q+1,Q+q+1);
	}
	for(int i=1; i<=q; ++i)printf("%d\n",ans[i]);
}
/*
4 3
1 2 4
2 3 3
3 1 1
3
1 3
1 4
1 3

*/