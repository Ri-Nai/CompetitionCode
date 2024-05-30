#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    int n,k;
    const int K=11,N=1e3+5;
    queue<int>Q;
    bool mark[N];
    struct algo
    {
        int H[K],L[K];
        void input(int id)
        {
            int t=0;
            for(int i=1;i<=k;++i)cin>>L[i],t|=L[i];
            for(int i=1;i<=k;++i)cin>>H[i];
            if(!t)Q.push(id),mark[id]=1;
        }
    }A[N];
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)A[i].input(i);
        int ans=0;
        while(!Q.empty())
        {
            int u=Q.front();
            ++ans;
            Q.pop();
            for(int i=1;i<=n;++i)
            {
                if(mark[i])continue;
                int t=0;
                for(int j=1;j<=k;++j)
                    t|=A[i].L[j]>A[u].H[j];
                if(t==0)Q.push(i),mark[i]=1;
            }
        }
        cout<<ans<<'\n';

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    T::solve();

}
