#include<cstdio>
const int maxn=1e5+5;

int n,m;
int fa[maxn<<1];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=2*n;++i)fa[i]=i;
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		//int x=find(a),y=find(b);
		int xa=find(a),ya=find(a+n),
			xb=find(b),yb=find(b+n);
		if(xa==xb||ya==yb)
		{
			puts("there are must be something wrong");
			return 0;
		}
		//fa[y]=x;
		fa[xa]=yb,fa[ya]=xb;
	}
	puts("it's your own problem");
}