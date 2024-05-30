#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=5005;
    int n,nx,ny;
    int X[N],Y[N],tmp[N],X0[N],Y0[N];
    int sumX[N][N],sumY[N][N];
    int ans;
    void lsh(int *A,int &t)
    {
        for(int i=1;i<=n;++i)
            tmp[i]=A[i];
        sort(tmp+1,tmp+n+1);
        t=unique(tmp+1,tmp+n+1)-tmp-1;
        for(int i=1;i<=n;++i)
            A[i]=lower_bound(tmp+1,tmp+t+1,A[i])-tmp;
    }
    void check(int a,int b)
    {
        if(a==b)return;
        if(X[b]<=X[a] or Y[b]<=Y[a])return;
        if(X0[b]-X0[a]!=Y0[b]-Y0[a])return;
        int x1=X[a],x2=X[b],y1=Y[a],y2=Y[b];
        if(!(sumX[y1][x2]-sumX[y1][x2-1]))return;
        if(!(sumX[y2][x1]-sumX[y2][x1-1]))return;
        int A[5];
        A[1]=sumX[y1][x2]-sumX[y1][x1-1];
        A[2]=sumX[y2][x2]-sumX[y2][x1-1];
        A[3]=sumY[x1][y2]-sumY[x1][y1-1];
        A[4]=sumY[x2][y2]-sumY[x2][y1-1];
        int cnt=0;
        for(int i=1;i<=4;++i)
            cnt+=A[i]>2;
        ans+=cnt<=3;
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>X[i]>>Y[i];
        memcpy(X0,X,sizeof X);
        memcpy(Y0,Y,sizeof Y);
        lsh(X,nx);lsh(Y,ny);
        for(int i=1;i<=n;++i)
            ++sumX[Y[i]][X[i]],++sumY[X[i]][Y[i]];
        for(int i=1;i<=nx;++i)
            for(int j=1;j<=ny;++j)
                sumY[i][j]+=sumY[i][j-1];
        for(int i=1;i<=ny;++i)
            for(int j=1;j<=nx;++j)
                sumX[i][j]+=sumX[i][j-1];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                check(i,j);
        End(ans);
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
