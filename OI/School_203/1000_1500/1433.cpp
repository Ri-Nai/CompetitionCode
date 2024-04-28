#include<bits/stdc++.h>
using namespace std;
char s[10][10],mp[4]={'R','L','D','U'};
int n,m,dx[4]= {0,0,1,-1},dy[4]= {1,-1,0,0},kx[3],ky[3];
bool mark[10][10][10][10][10][10][10][10];
struct point
{
    int x,y,step;
    int b[10][10];
    int bx[5],by[5];
} p;
inline bool pd(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)return 0;
    if(s[x][y]=='#')return 0;
    return 1;
}
inline bool pd2(point p,int t)
{
    if(p.b[p.x][p.y]&&!p.b[p.x+dx[t]][p.y+dy[t]]&&pd(p.x+dx[t],p.y+dy[t]))return 1;
    return 0;
}
void scan()
{
    int cnt=0,num=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)
    {
        scanf("%s",s[i]);
        for(int j=0; j<m; ++j)
        {
            if(s[i][j]=='X')p.x=i,p.y=j;
            if(s[i][j]=='*')
            {
                ++cnt;
                p.b[i][j]=cnt;
                p.bx[cnt]=i;
                p.by[cnt]=j;
            }
            if(s[i][j]=='@')
            {
                kx[num]=i;
                ky[num]=j;
                ++num;
            }
        }
    }
}
int main ()
{
    scan();
    p.step=0;
    queue<point> q;
    q.push(p);
    mark[p.x][p.y][p.bx[1]][p.by[1]][p.bx[2]][p.by[2]][p.bx[3]][p.by[3]]=1;
    while(!q.empty())
    {
        point p0=q.front();
        q.pop();
        bool flag=1;
        for(int i=0; i<3; ++i)
        {
             
            if(!p0.b[kx[i]][ky[i]])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<p0.step<<endl;
            return 0;
        }
        for(int i=0; i<4; ++i)
        {
            point pp=p0;
            pp.x+=dx[i];
            pp.y+=dy[i];
            pp.step++;
            if(!pd(pp.x,pp.y))continue;
            if(pd2(pp,i))
            {
                int t=pp.b[pp.x][pp.y];
                pp.b[pp.x][pp.y]=0;
                pp.b[pp.x+dx[i]][pp.y+dy[i]]=t;
                pp.bx[t]+=dx[i];pp.by[t]+=dy[i];
            }
            else if(pp.b[pp.x][pp.y])continue;
            if(!mark[pp.x][pp.y][pp.bx[1]][pp.by[1]][pp.bx[2]][pp.by[2]][pp.bx[3]][pp.by[3]])
            {
                q.push(pp);
                mark[pp.x][pp.y][pp.bx[1]][pp.by[1]][pp.bx[2]][pp.by[2]][pp.bx[3]][pp.by[3]]=1;
            }
        }
    }
    cout<<-1;
}