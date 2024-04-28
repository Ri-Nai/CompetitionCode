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
    const int N=2e5+5;
    char s[2][N];
    #define get(x,y) ((x)*(n)+(y))
    void solve()
    {
        int n=rd();
        vector<vector<int>>E(2*n);
        scanf("%s",s[0]);
        scanf("%s",s[1]);
        for(int i=0;i<2;++i)
            for(int j=0;j<n;++j)
            {
                if(i+j&1)
                {
                    if(s[i][j]=='>')
                    {
                        if(j!=n-1)E[get(i,j)].push_back(get(i,j+1));
                    }
                    else if(j!=0)E[get(i,j)].push_back(get(i,j-1));
                }
                else
                {
                    if(j!=n-1)E[get(i,j)].push_back(get(i,j+1));
                    if(j!=0)E[get(i,j)].push_back(get(i,j-1));
                    if(i!=0)E[get(i,j)].push_back(get(i-1,j));
                    if(i!=1)E[get(i,j)].push_back(get(i+1,j));
                }
            }
        queue<int>Q;
        Q.push(0);
        vector<bool>vis(n<<1);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int v:E[u])
                if(!vis[v])Q.push(v),vis[v]=1;
        }
        if(vis[n+n-1])puts("YES");
        else puts("NO");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
