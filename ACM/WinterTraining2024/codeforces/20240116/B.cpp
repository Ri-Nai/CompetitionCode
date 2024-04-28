#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    char s[3][3];
    bool mark[3][3];
    int dx[]={1,0,-1,0,1,1,-1,-1};
    int dy[]={0,1,0,-1,1,-1,1,-1};
    string ans;
    bool check(int x,int y)
    {
        if(x<0 || x>=3 || y<0 ||y>=3)return 0;
        if(mark[x][y])return 0;
        return 1;
    }
    void dfs(int num,string res,int x,int y)
    {
        if(num==3)
        {
            ans=min(ans,res);
            return ;
        }
        mark[x][y]=1;
        for(int i=0;i<8;++i)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(check(nx,ny))
                dfs(num+1,res+s[nx][ny],nx,ny);
        }
        mark[x][y]=0;
    }
    void solve()
    {
        ans="CCC";
        for(int i=0;i<3;++i)
            cin>>s[i];
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
            {
                string tmp="";
                tmp+=s[i][j];
                dfs(1,tmp,i,j);
            }
        cout<<ans<<'\n';
    }
}
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
