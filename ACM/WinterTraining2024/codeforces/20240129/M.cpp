#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=105;
    int n,A[N],ans[N],ansp[N];
    int L[N],R[N];
    bool mark[N];
    int mx;
    vector<vector<int>>E;
    void dfs(int x)
    {
        if(x==n+1)
        {
            int res=0;
            for(int i=1;i<=n;++i)
                L[i]=i-1,R[i]=i+1;
            L[1]=n;R[n]=1;
            for(int i=1;i<n;++i)
            {
                int p=ans[i];
                res+=A[p]*A[L[p]]*A[R[p]];
                L[R[p]]=L[p];
                R[L[p]]=R[p];
            }
            res+=A[ans[n]];
            if(res>mx)
            {
                mx=res;
                E.clear();
                vector<int>p;
                for(int i=1;i<=n;++i)
                    p.push_back(ans[i]);
                E.push_back(p);
            }
            else if(res==mx)
            {
                vector<int>p;
                for(int i=1;i<=n;++i)
                    p.push_back(ans[i]);
                E.push_back(p);
            }
            return ;
        }
        for(int i=1;i<=n;++i)
            if(!mark[i])
            {
                mark[i]=1;
                ans[x]=i;
                dfs(x+1);
                mark[i]=0;
            }
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i];
        dfs(1);
        cout<<mx<<'\n';
        // for(int i=1;i<=n;++i)
            // cout<<ansp[i]<<' '<<A[ansp[i]]<<'\n';
        cout<<E.size()<<'\n';
        for(auto T:E)
        {
            for(int x:T)cout<<x<<' '<<A[x]<<'\n';
            cout<<'\n';
        }
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
