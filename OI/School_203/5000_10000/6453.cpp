#include<cmath>
#include<cstdio>
#include<bitset>
#include<algorithm>
const int maxn=1e4+6;
int n,m,S,blk[maxn],bl[maxn],br[maxn],
A[maxn],B[maxn<<1],cnt,tot,X[maxn],Y[maxn];
std::bitset<maxn*2>is[105],res;//每个块
bool mark[maxn];
void update(int x,int y)
{
	A[x]=std::lower_bound(B,B+cnt,y)-B+1;
	is[blk[x]].reset();
	for(int i=bl[blk[x]];i<br[blk[x]];++i)
		is[blk[x]][A[i]]=1;

}
int query(int L,int R)
{
	res.reset();
    if(blk[L]==blk[R])for(int i=L;i<=R;++i)res[A[i]]=1;
    else
    {
        for(int i=L;i<br[blk[L]];++i)res[A[i]]=1;
        for(int i=bl[blk[R]];i<=R;++i)res[A[i]]=1;
        for(int i=blk[L]+1;i<blk[R];++i)res|=is[i];
    }
    return res.count();
}
int main()
{
    scanf("%d%d",&n,&m);S=sqrt(n);
    for(int i=0;i<n;++i)scanf("%d",&A[i]),B[cnt++]=A[i];
    for(int i=1,x,y;i<=m;++i)
    {
        char tmp[6];
        scanf("%s%d%d",tmp,&x,&y);
        if(tmp[0]=='Q')mark[i]=1,X[i]=x-1,Y[i]=y-1;
        else mark[i]=0,X[i]=x-1,B[cnt++]=Y[i]=y;
    }
    std::sort(B,B+cnt);
    cnt=std::unique(B,B+cnt)-B;
    for(int i=0;i<n;++i)A[i]=std::lower_bound(B,B+cnt,A[i])-B+1,tot=blk[i]=i/S;
    for(int i=0;i<=tot;++i)
	{
		bl[i]=i*S,br[i]=i*S+S;
		if(br[i]>n)br[i]=n;
		for(int j=bl[i];j<br[i];++j)
			is[i][A[j]]=1;
	}
	for(int i=1;i<=m;++i)
	{
		if(mark[i])printf("%d\n",query(X[i],Y[i]));
		else update(X[i],Y[i]);
	}
}