#include<cstdio>
#include<algorithm>
#define Fasdasd
const int maxn=2e5+5;
struct Edge
{
	int u,v,w;
	bool operator <(const Edge &e)const
	{
		return w>e.w;
	}
}E[maxn];
int num[maxn],cnt,mxw,
n,m,father[maxn];
long long ans[maxn],sum;
void read(int &x)
{
	x=0;
	int c;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void put(long long x)
{
	char c[20];
	int len=0;
	do c[++len]=(x%10)^48,x/=10;while(x);
	while(len)putchar(c[len--]);
	putchar(' ');
}
inline int find(const int &x)
{
	return x==father[x]?x:father[x]=find(father[x]);
}
inline void Add(int u,int v,int w)
{
	++cnt;
	E[cnt]=(Edge){u,v,w};
	if(w>mxw)mxw=w;
}
void pre()
{
	read(n),read(m);
	for(int i=1,u,v,w;i<n;++i)
		read(u),read(v),read(w),
		Add(u,v,w);
	std::sort(E+1,E+cnt+1);
	for(int i=1;i<=n;++i)
		father[i]=i,
		num[i]=1;
}
void solve()
{
	pre();
	int now=1;
	for(int i=mxw;i;--i)
	{
		if(now<=cnt&&E[now].w==i)
			while(now<=cnt&&E[now].w==i)
			{
//				printf("%d %d %d\n",E[now].u,E[now].v,E[now].w);
				int fa=find(E[now].u),
					fb=find(E[now].v);
				//这个组的数量
				sum-=1ll*num[fa]*(num[fa]-1)+1ll*num[fb]*(num[fb]-1);
				//减去已有的
				//printf("%d %d\n***\n",num[fa],num[fb]);
				num[fa]+=num[fb];
				//printf("%d %d\n---\n",num[fa],num[fb]);
				father[fb]=fa;
				//printf("%d %d\n",fa,num[fa]);
				//合并操作 
				//printf("%d ",num[fa]);
				sum+=1ll*num[fa]*(num[fa]-1);
				//加回现有的 
				//printf("%d\n",sum);
				++now;
			}
		ans[i]=sum/2;
	}
	int x;
	while(m--)
	{
		read(x);
		if(x>mxw)put(0ll);
		else put(ans[x]);
	}
}
int main()
{
	#ifndef F
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
