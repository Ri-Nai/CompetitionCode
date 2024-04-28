#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e5+5;
int n,k,m,tot,save[M],mp[N][N];
char s[6];
struct Ques
{
    int opt,c,x1,y1,x2,y2;
    void read(int i)
    {
        scanf("%s",s);
        if(*s=='P')opt=1,scanf("%d%d%d%d%d",&c,&x1,&y1,&x2,&y2);
        else if(*s=='S')opt=2,save[++tot]=i;
        else opt=3,scanf("%d",&c);
    }
}Q[M];
struct DSU
{
    int fa[N];
    DSU(){for(int i=0;i<N;++i)fa[i]=i;}
    int find(int u)
    {
        return u==fa[u]?u:fa[u]=find(fa[u]);
    }
    void Union(int u,int v){fa[u]=v;}
}X[N];
//用并查集找到这段被染色后的下一个未被染色的节点
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)mp[i][j]=1;
    for(int i=1;i<=m;++i)Q[i].read(i);
    for(int i=m;i;--i)
    {
        // Rn_1(i);
        if(Q[i].opt==3)i=save[Q[i].c];
        if(Q[i].opt==2)continue;
        for(int j=Q[i].x1,p=0;j<=Q[i].x2;++j,p^=1)
            for(int k=X[j].find(Q[i].y1+p);k<=Q[i].y2;k=X[j].find(k))
                mp[j][k]=Q[i].c,X[j].Union(k,k+2);
        // puts("AAAAAAA");
    }
    for(int i=0;i<n;++i,putchar('\n'))
        for(int j=0;j<n;++j,putchar(' '))
            printf("%d",mp[i][j]);
}
