#include<cmath>
#include<cstdio>
#include<algorithm>
const int maxn=1e5+6;
int n,m,A[maxn],B[maxn],S;
void update(int x,int y)
{
    int block=x/S,L=block*S,R=L+S;
    B[x]=y;if(R>n)R=n;
    for(int i=L;i<R;++i)A[i]=B[i];
    std::sort(A+L,A+R);
}
int Cnt(int L,int R,int num)
{
    int l=L/S,r=R/S,res=0;
    if(l==r)
    {
        for(int i=L;i<=R;++i)
            if(B[i]<num)++res;
    }
    else
    {
        for(int i=L;i<l*S+S;++i)
            if(B[i]<num)++res;
        for(int i=r*S;i<=R;++i)
            if(B[i]<num)++res;
        for(int i=l+1;i<r;++i)
        {
            int lft=i*S,rit=i*S+S;
            res+=(std::lower_bound(A+lft,A+rit,num)-A-lft);
        }
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
    int T;scanf("%d",&T);
    while(T--)
    {

        scanf("%d%d",&n,&m);S=sqrt(n);
        for(int i=0;i<n;++i)scanf("%d",&A[i]),B[i]=A[i];
        for(int i=0;i<=S;++i)
        {
            int L=i*S,R=i*S+S;
            if(R>n)R=n;
            std::sort(A+L,A+R);
        }
        for(int i=1,x,y,z;i<=m;++i)
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
}