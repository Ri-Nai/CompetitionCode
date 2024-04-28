#include<cmath>
#include<cstdio>
#include<cstring>
const int maxn=1e5+5,maxS=80;
int n,m,A[maxn],id[maxn],S,sz[maxS],
blk[maxn],bl[maxS],br[maxS],tot;
long long ans;
bool mark[maxn];
struct BIT
{
	int C[maxn];
	BIT(){memset(C,0,sizeof C);}
	void Add(int x,int y){while(x<maxn)C[x]+=y,x+=x&-x;}
	int sum(int x){int res=0;while(x)res+=C[x],x-=x&-x;return res;}
}C[maxS],T;
void in_put()
{
	scanf("%d%d",&n,&m);
	S=sqrt(1.0*n*log(n)/log(2));
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),id[A[i]]=i;
	for(int i=1;i<=n;++i)blk[i]=(i-1)/S+1;tot=blk[n];
	for(int i=1;i<=blk[n];++i)
	{
		bl[i]=i*S-S+1;br[i]=i*S;
		if(br[i]>n)br[i]=n;sz[i]=br[i]-bl[i]+1;
		for(int j=bl[i];j<=br[i];++j)
			C[i].Add(A[j],1);
	}
}
void update(int x,int id)
{
	for(int i=bl[blk[id]];i<=id-1;++i)
		if(!mark[i]&&A[i]>x)--ans;
	for(int i=id+1;i<=br[blk[id]];++i)
		if(!mark[i]&&A[i]<x)--ans;
	mark[id]=1;
	for(int i=1;i<blk[id];++i)ans-=sz[i]-C[i].sum(x);
	for(int i=blk[id]+1;i<=tot;++i)ans-=C[i].sum(x);
	C[blk[id]].Add(x,-1);--sz[blk[id]];
}
int main()
{
	in_put();
	for(int i=1;i<=n;++i)
		ans+=i-1-T.sum(A[i]),T.Add(A[i],1);
	for(int i=1,x;i<=m;++i)
	{
		printf("%lld\n",ans);
		scanf("%d",&x);
		update(x,id[x]);
	}
}