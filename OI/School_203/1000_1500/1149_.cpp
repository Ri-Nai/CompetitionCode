#include<cstdio>
#include<cstring>
const int P=1000;
int n,m,Q;
struct Matrix
{
    int M[20][20];
    Matrix(){memset(M,0,sizeof M);}
    Matrix operator *(const Matrix &_)
    {
        Matrix A;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                for(int k=0;k<n;++k)
                    (A.M[i][j]+=M[i][k]*_.M[k][j]%P)%=P;
        return A;
    }
}F[30],ans;
int query(int A,int B,int K)
{
    memset(ans.M,0,sizeof ans.M);
    ans.M[A][A]=1;
    for(int i=0;K;++i,K>>=1)
        if(K&1)ans=ans*F[i];
    return ans.M[A][B];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;++i)
        scanf("%d%d",&u,&v),
        F[0].M[u][v]=1;
    scanf("%d",&Q);
    for(int i=1;i<=30;++i)F[i]=F[i-1]*F[i-1];
    for(int i=1,A,B,K;i<=Q;++i)
        scanf("%d%d%d",&A,&B,&K),
        printf("%d\n",query(A,B,K));
}