#include<cstdio>
const int maxn=2e4+5;

int n,m,ans;
int fa[maxn];
bool mark[maxn];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a=find(a),b=find(b);
		fa[a]=b;
	}
	for(int i=1;i<=n;++i)if(!mark[find(i)])mark[find(i)]=1,++ans;
	printf("%d\n",ans);
}
