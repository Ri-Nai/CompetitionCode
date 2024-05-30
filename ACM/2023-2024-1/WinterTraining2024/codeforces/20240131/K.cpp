#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    typedef vector<vector<int>> darr;
    darr S;
    int n,m;
    map<darr,int>mp;
    int dfs(darr A,int t)
    {
        if(!t or mp[A])return mp[A];
        int res=t;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(A[i][j])
                {
                    if(j<m-2 && A[i][j+1] && !A[i][j+2])
                    {
                        A[i][j]^=1,A[i][j+1]^=1,A[i][j+2]^=1;
                        res=min(res,dfs(A,t-1));
                        A[i][j]^=1,A[i][j+1]^=1,A[i][j+2]^=1;
                    }
                    if(i<n-2 && A[i+1][j] && !A[i+2][j])
                    {
                        A[i][j]^=1,A[i+1][j]^=1,A[i+2][j]^=1;
                        res=min(res,dfs(A,t-1));
                        A[i][j]^=1,A[i+1][j]^=1,A[i+2][j]^=1;
                    }
                }
                else
                {
                    if(j<m-2 && A[i][j+1] && A[i][j+2])
                    {
                        A[i][j]^=1,A[i][j+1]^=1,A[i][j+2]^=1;
                        res=min(res,dfs(A,t-1));
                        A[i][j]^=1,A[i][j+1]^=1,A[i][j+2]^=1;
                    }
                    if(i<n-2 && A[i+1][j] && A[i+2][j])
                    {
                        A[i][j]^=1,A[i+1][j]^=1,A[i+2][j]^=1;
                        res=min(res,dfs(A,t-1));
                        A[i][j]^=1,A[i+1][j]^=1,A[i+2][j]^=1;
                    }
                }
            }
        }
        return mp[A]=res;
    }
    void solve()
    {
        int k;
        cin>>n>>m>>k;
        S.assign(n,vector<int>(m,0));
        for(int i=1;i<=k;++i)
        {
            int x,y;
            cin>>x>>y;
            --x,--y;
            S[x][y]=1;
        }
        cout<<dfs(S,k)<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
