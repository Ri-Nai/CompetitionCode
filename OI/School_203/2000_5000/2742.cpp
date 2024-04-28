#include<bits/stdc++.h>
using namespace std;
bool Nai;
const int N=5005,M=5e5+5,P=M*25;
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
#define LR int L=1,int R=K,int p=1
int sz[N],fa[N],n,m,Q,op[N],K;
int find(int u)
{
	return u==fa[u]?u:find(fa[u]);
}
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
struct CP
{
	int u,v;
	void read(int i)
	{
		op[i]=rd();
		u=rd();v=rd();
		if(op[i]==2)++K;
		if(u>v)swap(u,v);
		// if(u==v)return --i,--Q,void();
	}
	int GHS()
	{
		return u*5001+v;
	}
}Ask[M],Que[M],to[P];
CP SSH(int hs)
{
	return (CP){hs/5001,hs%5001}
}
int nxt[P],pre[P],head[M<<2],Head[M<<2],tot;
void Add(int u,const CP &v)
{
	nxt[++tot]=head[u];
	pre[head[u]]=tot;
	if(!head[u])Head[u]=tot;
	to[head[u]=tot]=v;
}
map<CP,int>id;
void Union(int &u,int &v)
{
	u=find(u);v=find(v);
	if(u==v)return;
	if(sz[u]>sz[v])swap(u,v);
	fa[u]=v;sz[v]+=sz[u];
}
void Split(int u,int v)
{
	if(u==v)return;
	fa[u]=u;sz[v]-=sz[u];
}
void Updata(int l,int r,const CP &pr,LR)
{
	if(l>r)return;
    if(L==l&&R==r)return Add(p,pr);
    int mid=L+R>>1;
    if(r<=mid)Updata(l,r,pr,Lson);
    else if(l>mid)Updata(l,r,pr,Rson);
    else Updata(l,mid,pr,Lson),Updata(mid+1,r,pr,Rson);
}
void Solve(LR)
{
	for(int i=head[p];i;i=nxt[i])Union(to[i].u,to[i].v);
	if(L==R)puts(find(Que[L].u)==find(Que[R].v)?"Y":"N");
	else {int mid=L+R>>1;Solve(Lson);Solve(Rson);}
	for(int i=Head[p];i;i=pre[i])Split(to[i].u,to[i].v);
}
bool Ri;
int main()
{
	// printf("%.6f",(&Ri-&Nai)/1024.0/1024);
	n=rd();Q=rd();
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	for(int i=1;i<=Q;++i)Ask[i].read(i);
	if(!K)return 0;
	for(int i=1;i<=Q;++i)
	{
		if(op[i]==2)
		{
			Que[++m]=Ask[i];
			if(m==K)break;
			continue;
		}
		if(op[i]==0)id[Ask[i]]=m+1;
		else Updata(id[Ask[i]],m,Ask[i]),id.erase(Ask[i]);
	}
	for(map<CP,int>::iterator it=id.begin();it!=id.end();++it)
		Updata(it->second,m,it->first);
	Solve();
}