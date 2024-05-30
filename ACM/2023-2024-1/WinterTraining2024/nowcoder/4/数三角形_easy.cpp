#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    char s[505][505];
    int S[505][505];
    bool check(int x,int y1,int y2)
    {
        return S[x][y2]-S[x][y1-1]==y2-y1+1;
    }
    void solve()
    {
        int n=rd(),m=rd();
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s[i]+1);
            for(int j=1;j<=m;++j)
                S[i][j]=S[i][j-1]+(s[i][j]=='*');
        }
        int ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                if(check(i,j,j))for(int k=1;;++k)
                {
                    int ly=j-k,ry=j+k;
                    int x=i+k;
                    if(ly<=0)break;
                    if(ry>m)break;
                    if(x>n)break;
                    if(!check(x,ly,ly) or !check(x,ry,ry))
                        break;
                    if(check(x,ly+1,ry-1))
                        ++ans;
                }
            }
        cout<<ans<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
