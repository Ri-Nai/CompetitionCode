#include<cmath>
#include<cstdio>
const int maxn=1e6+6;
int n,m,A[maxn],S,blk[maxn],bl[maxn],
	br[maxn],tot,cnt[maxn],to[maxn];
void update(int x,int y)
{
	A[x]=y;
	for(int i=br[blk[x]]-1;i>=bl[blk[x]];--i)
	{
		to[i]=A[i]+i;
		if(A[i]+i>=br[blk[i]])cnt[i]=1;
		else cnt[i]=cnt[to[i]]+1,to[i]=to[to[i]];
	}
}
int query(int x)
{
	int res=0;
	while(x<n)res+=cnt[x],x=to[x];
	return res;
}
int main()
{
	scanf("%d",&n);S=sqrt(n);
	for(int i=0;i<n;++i)scanf("%d",&A[i]);
	for(int i=0;i<n;++i)tot=blk[i]=i/S;
	scanf("%d",&m);
	for(int i=0;i<=tot;++i)
	{
		bl[i]=i*S,br[i]=i*S+S;
		if(br[i]>n)br[i]=n;
	}
	for(int i=n-1;~i;--i)
	{
		to[i]=A[i]+i;
		if(A[i]+i>=br[blk[i]])cnt[i]=1;
		else cnt[i]=cnt[to[i]]+1,to[i]=to[to[i]];
	}
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d",&x);
		if(x==2)scanf("%d%d",&y,&z),update(y,z);
		else scanf("%d",&y),printf("%d\n",query(y));
	}
}