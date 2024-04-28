#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,A[N],B[N],C[N],cnt[N],stk[N],top,ans[N];
void RadixSort()
{
    const int m=(1<<16)-1;
    for(int i=1;i<=n;++i)A[i]+=1e9;
    for(int i=1;i<=n;++i)++cnt[A[i]&m];
    for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;--i)B[cnt[A[i]&m]--]=i;
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;++i)++cnt[A[B[i]]>>16&m];
    for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;--i)C[cnt[A[B[i]]>>16&m]--]=B[i];
    for(int i=1;i<=n;++i)B[i]=A[C[i]]-1e9;
    for(int i=1;i<=n;++i)A[i]-=1e9;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    RadixSort();
    memset(ans,0x3f,sizeof ans);
    // for(int i=1;i<=n;++i)
    //     printf("%d %d %d\n",A[i],B[i],C[i]);
    for(int i=1;i<=n;++i)
    {
        while(top&&stk[top]>C[i])--top;
        if(top)ans[C[i]]=abs(A[C[i]]-A[stk[top]]);
        stk[++top]=C[i];
    }
    top=0;
    for(int i=n;i>=1;--i)
    {
        while(top&&stk[top]>C[i])--top;
        if(top)ans[C[i]]=min(ans[C[i]],abs(A[C[i]]-A[stk[top]]));
        stk[++top]=C[i];
    }
    ans[1]=A[1];
    int Ans=0;
    for(int i=1;i<=n;++i)
        Ans+=ans[i];
    printf("%d\n",Ans);
}
