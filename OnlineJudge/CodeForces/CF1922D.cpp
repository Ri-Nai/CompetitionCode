#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=3e5+5;
    int n;
    int L[N],R[N];
    int A[N],D[N],ans[N],res[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            L[i]=i-1,R[i]=i+1,ans[i]=0,res[i]=0;
        A[n+1]=0;
        R[0]=1;L[n]=n-1;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)cin>>D[i];
        queue<int>Q;
        for(int i=1;i<=n;++i)Q.push(i);
        for(int i=1;i<=n;++i)
        {
            // vector<int>P;
            queue<int>P;
            vector<int>E;
            if(Q.empty())
                break;
            while(!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                // cout<<A[R[u]]<<' '<<A[L[u]]<<'\n';
                if(A[R[u]]+A[L[u]]>D[u])
                    P.push(u);
            }
            res[i]=P.size();
            while(!P.empty())
            {
                int u=P.front();
                P.pop();
                // cout<<u<<'\n';
                E.push_back(L[u]);
                E.push_back(R[u]);
                ans[u]=i;
                R[L[u]]=R[u];
                L[R[u]]=L[u];
            }
            // cout<<"**************\n";
            sort(E.begin(),E.end());
            E.erase(unique(E.begin(),E.end()),E.end());
            for(int i:E)
            {
                if(ans[i])continue;
                if(i==0 or i==n+1)continue;
                Q.push(i);
            }
        }
        for(int i=1;i<=n;++i)cout<<res[i]<<' ';
        cout<<'\n';
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
