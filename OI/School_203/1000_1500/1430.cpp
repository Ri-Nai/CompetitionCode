#include<cstdio>
#include<cstring>
int a[500],b[3][10],c[3][10],x,y,k;
bool mark[3][10];
void print()
{
    printf("%d",y);
    if(x==0)putchar('s');
    if(x==1)putchar('b');
    if(x==2)putchar('c');
    putchar(' ');
}
void dfs(int t)
{
    if(t==0)
    {
        ++k;
        if(!mark[x][y])print();
        mark[x][y]=1;
        return;
    }
    for(int i=0;i<3;++i)
        for(int j=1;j<10;++j)
        {
            if(c[i][j]>=3)
            {
                c[i][j]-=3;
                dfs(t-1);
                c[i][j]+=3;
            }
            if(j-2>=1)
            {
                if(c[i][j-2]>=1&&c[i][j-1]>=1&&c[i][j]>=1)
                {
                    c[i][j-2]--;
                    c[i][j-1]--;
                    c[i][j]--;
                    dfs(t-1);
                    c[i][j-2]++;
                    c[i][j-1]++;
                    c[i][j]++;
                }
            }
        }
}
void chuli()
{
    for(int i=0;i<3;++i)
        for(int j=1;j<10;++j)
            if(c[i][j]>=2)
            {
                c[i][j]-=2;
                dfs(4);
                c[i][j]+=2;
            }
}
int main ()
{
    a['s']=0,a['b']=1,a['c']=2;
    for(int i=0;i<13;++i)
    {
        char s[3];
        scanf("%s",s);
        ++b[a[s[1]]][s[0]-'0'];
    }
    for(int i=0;i<3;++i)
        for(int j=1;j<10;++j)
        {
            if(b[i][j]<4)
            {
                b[i][j]++;
                x=i,y=j;
                memcpy(c,b,sizeof(c));
                chuli();
                b[i][j]--;
            }
        }
    if(!k)puts("None");
}