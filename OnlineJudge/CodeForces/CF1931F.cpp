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
    void solve()
    {
        int n=rd(),m=rd();
        vector<vector<int>>E(n+1);
        vector<int>dis(n+1,1e9);
        vector<int>in(n+1,0);
        for(int i=1;i<=m;++i)
            for(int j=1,pre,now;j<=n;++j)
            {
                now=rd();
                if(j>2)
                {
                    E[now].push_back(pre);
                    ++in[pre];
                }
                pre=now;
            }
        queue<int>Q;
        for(int i=1;i<=n;++i)
            if(!in[i])Q.push(i);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(int v:E[u])if(!--in[v])Q.push(v);
        }
        for(int i=1;i<=n;++i)if(in[i])End("NO");
        End("YES");
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
