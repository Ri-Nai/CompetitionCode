#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=2e5+3;
    int n,k,A[M],in[M],mark[M];
    bool dfs(int i)
    {
        int x=1,t=A[i];--in[i];
        while(t!=i)--in[t],t=A[t],++x;
        return x!=k;
    }
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)in[i]=mark[i]=0;
        for(int i=1;i<=n;++i)cin>>A[i],++in[A[i]];
        if(k==1)
        {
            for(int i=1;i<=n;++i)
                if(A[i]!=i)End("No");
            End("YEs");
        }
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while(!mark[j] and !in[j])mark[j]=1,--in[A[j]],j=A[j];
        }
        for(int i=1;i<=n;++i)
            if(in[i])if(dfs(i))End("No");
        End("YES");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
