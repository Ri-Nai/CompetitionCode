#include<cstdio>
const int maxn=1e5+5;
int A[maxn],T[maxn],n;
long long cnt;
void msort(int L,int R)
{
    if(R!=L)
    {
        int mid=L+R>>1;
        msort(L,mid);msort(mid+1,R);
        int p=L,q=mid+1,i=L;
        while(p<=mid||q<=R)
            if(q>R||(A[p]<=A[q]&&p<=mid))T[i++]=A[p++];
            else T[i++]=A[q++],cnt+=mid-p+1;
        for(int j=L;j<=R;++j)A[j]=T[j];
    }
}
int main ()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    msort(1,n);printf("%lld\n",cnt);
}