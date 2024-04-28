#include<cmath>
#include<cstdio>
#include<algorithm>
#define Re register
const int maxn=1e4+6;
int n,m,A[maxn],B[maxn],S,blk[maxn],bl[maxn],br[maxn];
void update(int x,int y)
{
    B[x]=y;
    for(Re int i=bl[blk[x]];i<br[blk[x]];++i)A[i]=B[i];
    std::sort(A+bl[blk[x]],A+br[blk[x]]);
}
int Cnt(int L,int R,int num)
{
    int res=0;
    if(blk[L]==blk[R])
    {
        for(Re int i=L;i<=R;++i)
            if(B[i]<num)++res;
    }
    else
    {
        for(Re int i=L;i<br[blk[L]];++i)
            if(B[i]<num)++res;
        for(Re int i=bl[blk[R]];i<=R;++i)
            if(B[i]<num)++res;
        for(Re int i=blk[L]+1;i<blk[R];++i)
            res+=(std::lower_bound(A+bl[i],A+br[i],num)-A-bl[i]);
    }
    return res;
}
int query(int L,int R,int num)
{
    int l=0,r=1e9,res;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(Cnt(L,R,mid)<num)
            res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);S=sqrt(n);
    for(Re int i=0;i<n;++i)scanf("%d",&A[i]),B[i]=A[i];  
    for(Re int i=0;i<n;++i)blk[i]=i/S;
    for(Re int i=0;;++i)
    {
        bl[i]=i*S,br[i]=i*S+S;
        if(br[i]>n)br[i]=n;
        if(bl[i]>=br[i])break;
    	std::sort(A+bl[i],A+br[i]);
    }
    for(Re int i=1,x,y,z;i<=m;++i)
    {
        char tmp[6];
        scanf("%s",tmp);
        if(tmp[0]=='Q')
            scanf("%d%d%d",&x,&y,&z),
            printf("%d\n",query(x-1,y-1,z));
        else
            scanf("%d%d",&x,&y),
            update(x-1,y);
 
    }
}