#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vc;
typedef long long LL;
const int N=1e5+5;
vc pos[N];
int n,k,b,m,st[18][N];
void dfs(vc &p,LL now)
{
    int kk=p[0];
    for(int x=1;;++x)
    {
        for(int i=16;~i;--i)
            if(x<N&&st[i][x]<=kk)x+=1<<i;
        if(x>=N)break;
        vc::iterator it=lower_bound(pos[x].begin(),pos[x].end(),kk+1);
        vc tmp;
        while(it!=pos[x].end())
        {
            int y=*it++;
            for(int i=0;i<p.size();++i)
            {
                if(y<=p[i])break;
                printf("%lld\n",(now*b+x)%m);
                if(!(--k))exit(0);
                tmp.push_back(y);
            }
        }
        dfs(tmp,(now*b+x)%m);
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&k,&b,&m);
    for(int i=1,x;i<=n;++i)
        scanf("%d",&x),
        st[0][x]=i,
        pos[x].push_back(i);
    for(int i=1;i<=16;++i)
        for(int j=1;j<N;++j)
        {
            st[i][j]=st[i-1][j];
            int p=j+(1<<i-1);
            if(p<N)st[i][j]=max(st[i][j],st[i-1][p]);
        }
    vc tmp(1,0);dfs(tmp,0);
}