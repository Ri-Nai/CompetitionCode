#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8,mod=998244353;
typedef long long ll;
int n,m,ans;
bool mark[6][N];
bool pd(int x,int y)
{
    return x>=1 and y>=1 and x<=5 and y<=n and mark[x][y];
}
bool check(int x,int y)
{
    return !pd(x-1,y-1) and ! pd(x+1,y-1) and !pd(x-1,y+1) and ! pd(x+1,y+1);
}
void dfs(int x,int y)
{
    if(y>n)y=1,++x;
    if(x==6)
    {
        ++ans;
        return;
    }
    if(!mark[x][y] and check(x,y))
    {
        mark[x][y]=1;
        dfs(x,y+1);
        mark[x][y]=0;
    }
    dfs(x,y+1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        mark[x][y]=1;
    }
    dfs(1,1);
    cout<<ans<<'\n';
}
