#include<cstdio>
int n,tot,goal,L,R,A[20],bit[1<<15];
void write(int x)
{
    if(x>9)write(x/10);
    putchar((x%10)^'0');
}
void print()
{
    for(int i=0;i<n;++i)
        write(A[i]),putchar(' ');
    putchar('\n');
}
void dfs(int index,int lvis,int rvis,int row,int now=0,int nxt=0)
{
    if(row==goal)
    {
        ++tot;
        if(tot>=L&&tot<=R)print();
    }
    else
    {
        now=goal&(~(row|lvis|rvis));
        while(now)
        {
            nxt=now&(~now+1);
            now^=nxt;A[index]=bit[nxt];
            dfs(index+1,(lvis|nxt)<<1,(rvis|nxt)>>1,row|nxt);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&L,&R);
    for(int i=0;i<=n;++i)bit[1<<i]=i;
    goal=(1<<n)-1;
    dfs(0,0,0,0);
    write(tot);
    return 0;
}