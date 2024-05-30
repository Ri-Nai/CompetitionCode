#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
priority_queue<int,vector<int>,greater<int> >Q;
namespace T
{
    const int M=2506;
    int n,k;
    int A[M],B[M];
    void solve()
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)
            cin>>A[i],B[i]=A[i];
        int ans=0;
        for(bool flag=1;;flag=1)
        {
            for(int i=1;i<=n;++i)
            {
                A[i]=B[i];
                if(i>1 and B[i]<B[i-1])flag=0;
            }
            if(flag)break;
            int t=0;
            ++ans;
            for(int i=1;i<=n;++i)
            {
                Q.push(A[i]);
                if(i>=k)B[++t]=Q.top(),Q.pop();
            }
            while(!Q.empty())
            {
                B[++t]=Q.top();
                Q.pop();
            }
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
