#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int N=1e5+5;
    int A[N],C[N],n,in[N];
    bool mark[N];
    long long ans;
    void dfs(int x)
    {
        // puts("aaa");
        // system("pause");
        --in[x];
        int idx=x;
        for(int i=A[x];i!=x;i=A[i])
        {
            if(C[i]<C[idx])idx=i;
            --in[i];
        }
        for(int i=A[idx];i!=idx;i=A[i])
            printf("%d ",i);
        printf("%d ",idx);
    }
    void solve()
    {
        scanf("%d",&n);ans=0;
        for(int i=1;i<=n;++i)mark[i]=in[i]=0,scanf("%d",&A[i]);
        for(int i=1;i<=n;++i)scanf("%d",&C[i]),++in[A[i]];
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while(!mark[j] and !in[j])printf("%d ",j),mark[j]=1,j=A[j],--in[j];
        }
        for(int i=1;i<=n;++i)if(in[i])dfs(i);
        puts("");
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)T::solve();
}
