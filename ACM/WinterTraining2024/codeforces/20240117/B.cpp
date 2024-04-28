#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m,k;
    const int N=1e5+5;
    int A[N],B[N],ans[N];
    bool mark[N];
    void solve()
    {
        cin>>n>>k>>m;
        for(int i=0;i<n;++i)ans[i]=B[i]=0;
        for(int i=0;i<=k;++i)mark[i]=0;
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
            B[i]=mark[A[i]];
            mark[A[i]]^=1;
        }
        int t=m/n,p=m%n;
        for(int i=0;i<n;++i)
        {
            if(!mark[A[i]])
            {
                if(B[i])ans[i]=t;
            }
            else
            {
                if(t&1)
                {
                    ans[i]=t/2+B[i];
                }
                else ans[i]=t/2;
            }
        }
        for(int i=0;i<p;++i)
        {
            if(!mark[A[i]])
                ans[i]+=B[i];
            else
            {
                if(t&1)ans[i]+=!B[i];
                else ans[i]+=B[i];
            }
        }
        for(int i=0;i<n;++i)
            cout<<ans[i]<<" \n"[i==n-1];
        // cout<<'\n';

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
