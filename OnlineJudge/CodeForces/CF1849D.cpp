#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
    int res=0;char c;
    do c=getchar();while(c<48 or c>57);
    for(;c>=48 and c<=57;c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res;
}
namespace Solve
{
    const int M=3e5+5;
    int n,m,A[M],cnt,ans;
    /* struct Pair
    // {
    //     int rep,id,l,r,color;
    //     friend operator  < (Pair A,Pair B)
    //     {
    //         return A.rep<B.rep;
    //     }
    // }T[M];
    // void Main()
    // {
    //     priority_queue<Pair> Q;
    //     int n,cnt=0;
    //     scanf("%d",&n);
    //     for(int i=1;i<=n;++i)scanf("%d",&A[i]);
    //     for(int i=1;i<=n;++i)
    //     {
    //         if(A[i]!=0)
    //         {
    //             ++cnt;
    //             T[cnt].l=i-1;
    //             T[cnt].id=cnt;
    //             T[cnt].rep=0;
    //             T[cnt].color=1;
    //             for(;i<=n and A[i]!=0;++i)
    //                 if(A[i]==2)T[cnt].color=2;
    //             T[cnt].r=i;
    //         }
    //     }
    //     if(T[0].l==0)++T[0].rep;
    //     if(T[cnt].r==n+1)++T[cnt].rep;
    //     for(int i=1;i<=cnt;++i)
    //         if(T[i].color==2)A[T[i].l]=A[T[i].r]=-1,T[i+1].rep+=1,T[i-1].rep+=1;
    //         else Q.push(T[i]);
    //     while(!Q.empty())
    //     {
    //         Pair now=Q.top();
    //         Q.pop();
    //         if(now.rep==2)continue;
    //         if(~A[now.l] and now.l!=0)A[now.l]=-1,T[now.id-1].rep+=1;
    //         else if(~A[now.r] and now.r!=n+1)A[now.r]=-1,T[now.id+1].rep+=1;

    //     }
    //     for(int i=1;i<=n;++i)
    //         if(A[i]==0)++cnt;
    //     printf("%d\n",cnt);
    // }
    */
    void Main()
    {
        cnt=ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            if(x==0)A[++cnt]=0;
            else if(A[cnt])A[cnt]=max(A[cnt],x);
            else A[++cnt]=x;
        }
        if(A[cnt]==2)A[cnt]=1;
        if(A[0]==2)A[0]=1;
        // A[0]=0;A[cnt+1]=0;
        int now=0;
        for(int i=1;i<=cnt;++i)
        {
            if(A[i]==0)
            {
                if(now==2)now=0;
                else ++ans,now=1;
            }
            if(A[i]==1)
            {
                if(now==0)++ans,now=2;
                else now=1;
            }
            if(A[i]==2)
            {
                if(now==0)++ans,now=2;
                else now=2;
            }
        }
        printf("%d\n",ans);
    }
}
int main()
{
    Solve::Main();
}
