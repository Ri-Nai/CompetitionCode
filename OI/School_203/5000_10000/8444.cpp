#include<cstdio>
#include<algorithm>
const int maxn=2e5+5;
struct $
{
	int L,R,id;
	bool operator <($ _)const
	{
		return L<_.L;
	}
}A[maxn<<1];
int n,m,tot,p,fa[maxn<<1][25],ans[maxn];
void in_put()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&A[i].L,&A[i].R);
		A[i].id=i;if(A[i].R<A[i].L)A[i].R+=m;
	}
	std::sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
		A[i+n]=A[i],A[i+n].L+=m,A[i+n].R+=m;
}
void pre()
{
	tot=n<<1,p=1;
	for(int i=1;i<=tot;++i)
	{
		//printf("%d %d\n",A[i].L,A[i].R);
		while(p<=tot&&A[p].L<=A[i].R)++p;
		fa[i][0]=p-1;
	}
	for(int i=1;i<20;++i)
		for(int j=1;j<=tot;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
int get(int now)
{
	int mx=A[now].L+m,res=1;
	//printf("%d\n",mx);
	for(int i=19;i>=0;--i)
		if(A[fa[now][i]].R<mx)
		{
			now=fa[now][i];
			res+=1<<i;
		}
	//printf("%d\n",res);
	return res+1;
}
int main()
{
	in_put();
	pre();
	for(int i=1;i<=n;++i)
		ans[A[i].id]=get(i);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
}
