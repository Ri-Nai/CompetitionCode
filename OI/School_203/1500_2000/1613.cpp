#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2e5+5;
int n,m,C1[maxn],mark[maxn];
LL sum1,sum2,C2[maxn];
struct node
{
    int T,L,id;
    bool operator <(node _)const
    {
        return L>_.L;
    }
}A[maxn];
void Add1(int x,int y){while(x)C1[x]+=y,x-=x&-x;}
void Add2(int x,int y){while(x<maxn)C2[x]+=y,x+=x&-x;}
LL Sum1(int x){LL res=0;while(x<maxn)res+=C1[x],x+=x&-x;return res;}
LL Sum2(int x){LL res=0;while(x)res+=C2[x],x-=x&-x;return res;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&A[i].T,&A[i].L);
        A[i].id=i;
    }
    sort(A+1,A+n+1);
    for(int i=1;i<=n;++i)
    {
        mark[A[i].id]=i;
        sum1+=A[i].T;
        Add1(A[i].L,1);
        Add2(A[i].L,A[i].L);
        sum2+=Sum1(A[i].L)*A[i].L;
    }
    printf("%lld\n",sum1-sum2);
    int k,t,l;
    while(m--)
    {
        scanf("%d%d%d",&k,&t,&l);
        k=mark[k];sum1+=t-A[k].T;
        sum2-=Sum1(A[k].L)*A[k].L;
        sum2-=Sum2(A[k].L-1);
 
        Add1(A[k].L,-1);
        Add2(A[k].L,-A[k].L);
 
        Add1(l,1);
        Add2(l,l);
 
        sum2+=Sum1(l)*l;
        sum2+=Sum2(l-1);
        A[k].T=t,A[k].L=l;
        printf("%lld\n",sum1-sum2);
    }
}