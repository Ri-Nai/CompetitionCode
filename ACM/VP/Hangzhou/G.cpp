#include<bits/stdc++.h>
using namespace std;
const int N=3035;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<vector<int>>is(n+1,vector<int>(m+1,0));
    vector<pair<int,int>>P(k+1);
    vector<vector<int>>dis(n+1);
    for(int i=1;i<=k;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        P[i]={x,y};
        if(i!=1)is[x][y]=1;
    }
    for(int i=1;i<=n;++i)
    {
        char s[N];
        scanf("%s",s+1);
        dis[i].assign(m+1,1e9);
        for(int j=1;j<=m;++j)
            if(s[j]=='#')is[i][j]=1;
    }
    auto check=[&](int x,int y)->bool
    {
        if(x>n||y>m||x<1||y<1)return 0;
        return !is[x][y];
    };
    queue<pair<int,int>>Q;
    Q.push(P[1]);
    dis[P[1].first][P[1].second]=0;
    for(int i=0;;++i)
    {
        while(!Q.empty())
        {
            auto [x,y]=Q.front();
            if(dis[x][y]!=i)break;
            Q.pop();
            for(int j=0;j<4;++j)
            {
                int nx=x+dx[j],ny=y+dy[j];
                if(check(nx,ny)&&dis[nx][ny]>i+1)
                    dis[nx][ny]=i+1,Q.push({nx,ny});
            }
        }
        if(i<=k-2)
        {
            auto [x,y]=P[k-i];
            is[x][y]=0;
            for(int j=0;j<4;++j)
            {
                int nx=x+dx[j],ny=y+dy[j];
                if(check(nx,ny)&&dis[nx][ny]<=i)
                    dis[x][y]=i+1,Q.push({x,y});
            }
        }
        else if(Q.empty())break;
    }
    unsigned long long ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(dis[i][j]!=1e9)ans+=1ull*dis[i][j]*dis[i][j];
    cout<<ans<<'\n';
}
