#include<cstdio>
#define LL long long
LL n,Mi[16],A[16],B[16],M=1,ans,x,y;
void exgcd(LL a,LL b)
{
    if(b==0){x=1;y=0;return;}
    exgcd(b,a%b);
    int t=x;x=y,y=t-y*(a/b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        scanf("%d",&B[i]);
        M*=A[i];
    }
    for(int i=1;i<=n;++i)
    {
        Mi[i]=M/A[i];
        x=0,y=0;
        exgcd(Mi[i],A[i]);//逆元
        ans+=B[i]*Mi[i]*(x<0?x+A[i]:x);
    }
    printf("%lld",ans%M);
}