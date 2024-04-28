#include<bits/stdc++.h>
using namespace std;
int X0,X1,X2,Y1,Y2,vX,vY;
double A[5][5],B[5][5],ans[5];
void Guass()
{
    for(int i=1;i<=3;++i)
    {
        for(int j=i+1;j<=3;++j)
            if(fabs(B[j][i])>fabs(B[i][i]))
                swap(B[i],B[j]);
        for(int j=1;j<=3;++j)
        {
            if(j==i)continue;
            if(!B[i][i]){ans[3]=-1e9;return;}
            double tmp=B[j][i]/B[i][i];
            for(int k=1;k<=4;++k)
                B[j][k]-=tmp*B[i][k];
        }
    }
    for(int i=1;i<=3;++i)
    {
        if(!B[1][1]){ans[3]=-1e9;return;}
        ans[i]=B[i][4]/B[i][i];
    }
    if(-ans[2]/2/ans[1]>=X0)ans[3]=-1e9;
    if(ans[1]>0)ans[3]=-1e9;
}
double Calc(int X,int Y)
{
    for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)
            B[i][j]=A[i][j];
    B[3][1]=1ll*X*X;
    B[3][2]=X;
    B[3][3]=1;
    B[3][4]=Y;
    Guass();
    double yy1=ans[1]*X1*X1+ans[2]*X1+ans[3];
    double yy2=ans[1]*X2*X2+ans[2]*X2+ans[3];
    if(Y1<=yy2 and Y1>=yy1)return -119;
    return ans[3];
}
void Solve()
{
    // cin>>X0>>X1>>X2>>Y1>>Y2>>vX>>vY;
    scanf("%d%d%d%d%d%d%d",&X0,&X1,&X2,&Y1,&Y2,&vX,&vY);
    A[1][1]=1ll*X0*X0;
    A[1][2]=X0;
    A[1][3]=1;
    A[1][4]=0;
    A[2][1]=2ll*X0*vX;
    A[2][2]=vX;
    A[2][3]=0;
    A[2][4]=vY;
    double h1=Calc(-X1,Y1);
    double h2=Calc(-X2,Y1);
    h1=max(h1,1.*Y1);
    h2=min(h2,1.*Y2);
    // cout<<h2-h1<<'\n';
    printf("%.2lf\n",max(0.,h2-h1));
}
int main()
{
    // ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--)Solve();
}
