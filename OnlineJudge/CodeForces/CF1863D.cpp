#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=505;
    int n,m,num1[M],num2[M];
    char S[M][M],bw[3]="BW",ans[M][M];
    void solve()
    {
        memset(num1,0,sizeof num1);
        memset(num2,0,sizeof num2);
        memset(ans,0,sizeof ans);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%s",S[i]+1);
        for(int i=1;i<=n;++i)
        {
            int cnt=0;
            for(int j=1;j<=m;++j)
                if(S[i][j]=='U' or S[i][j]=='D')++cnt;
            if(cnt&1)return puts("-1"),void();
        }
        for(int i=1;i<=m;++i)
        {
            int cnt=0;
            for(int j=1;j<=n;++j)
                if(S[j][i]=='L' or S[j][i]=='R')++cnt;
            if(cnt&1)return puts("-1"),void();
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                if(!ans[i][j])ans[i][j]='.';
                int x=num1[i]>=0,flag=x?-1:1;
                if(S[i][j]=='U')
                    ans[i][j]=bw[x],ans[i+1][j]=bw[x^1],num1[i]+=flag,num1[i+1]-=flag;
            }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                int x=num2[i]>=0,flag=x?-1:1;
                if(S[j][i]=='L')
                    ans[j][i]=bw[x],ans[j][i+1]=bw[x^1],num2[i]+=flag,num2[i+1]-=flag;
            }
        }
        for(int i=1;i<=n;++i,puts(""))
            for(int j=1;j<=m;++j)putchar(ans[i][j]);

    }
}
int main()
{
    int t;cin>>t;
    while(t--)T::solve();
}
