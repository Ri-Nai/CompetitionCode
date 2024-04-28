#include<cstdio>
int n,m,A[51];
double f[51][51];
int main()
{
    scanf("%d%d",&n,&m);f[1][1]=1;
    for(int i=1;i<=m;++i)scanf("%d",&A[i]);
    for(int i=2;i<=n;++i)
        for(int j=2;j<=i;++j)
            for(int k=1,x;k<=m;++k)
                x=(j+A[k]-1+i-1)%i+1,f[i][x]+=f[i-1][j-1]/m;
    for(int i=1;i<=n;++i)printf("%.2f%% ",f[n][i]*100);
}