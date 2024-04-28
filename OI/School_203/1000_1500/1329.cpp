#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
int dx[4]={1,0,0,-1},dy[4]={0,-1,1,0},b[256],ans=0x3f3f3f3f,flag=-1;
bool mark[10][10][10][10][10][10][10][10];
struct Eight
{
    char c[3][4],cc[10];
    int x,y,len;
}a;
bool pd(int x,int y){return x<3&&y<3&&x>=0&&y>=0;}
int main ()
{
    for(int i=1;i<=8;++i)b[i+48]=i;
    b['x']=9;
    int xx=0;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        {
            std::cin>>a.c[i][j];
            a.cc[xx]=a.c[i][j];
            ++xx;
            if(a.c[i][j]=='x')a.x=i,a.y=j;
        }
    a.len=0;
    char *s=a.cc;
    mark[b[s[0]]][b[s[1]]][b[s[2]]][b[s[3]]][b[s[4]]][b[s[5]]][b[s[6]]][b[s[7]]]=1;
    std::queue<Eight> q;
    q.push(a);
    while(!q.empty())
    {
        Eight e;e=q.front();q.pop();
        bool k=1,p=0;
        for(int i=0;i<8;++i)
            if(b[e.cc[i]]!=i+1)k=0;
        //printf("%d\n",ans);
        //printf("%d\n",e.len);
        // if(e.len>ans)break;
        // if(k&&flag==-1)ans=e.len,flag=1;
        // else if(k&&flag!=-1)++flag;
        if(k){ans=e.len;break;}
        for(int i=0;i<4;++i)
        {
            if(pd(e.x+dx[i],e.y+dy[i]))
            {
                Eight f=e;
                std::swap(f.c[e.x][e.y],f.c[e.x+dx[i]][e.y+dy[i]]);
                f.x+=dx[i];f.y+=dy[i];++f.len;
                int nn=0;
                for(int j=0;j<3;++j)
                    for(int z=0;z<3;++z)
                        f.cc[nn]=f.c[j][z],++nn;
                char *s=f.cc;
                //printf("%c %c\n",s[0],s[1]);
                if(!mark[b[s[0]]][b[s[1]]][b[s[2]]][b[s[3]]]
                        [b[s[4]]][b[s[5]]][b[s[6]]][b[s[7]]])
                    q.push(f),mark[b[s[0]]][b[s[1]]][b[s[2]]][b[s[3]]]
                                  [b[s[4]]][b[s[5]]][b[s[6]]][b[s[7]]]=1;
            }
        }
    }
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
}