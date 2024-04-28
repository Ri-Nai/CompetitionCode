#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=4e4+5;
    int A[M],B[M],C[M],n;
    bool cmp(int x,int y)
    {
        return A[x]>A[y];
    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i],B[i]=i;
        sort(B+1,B+n+1,cmp);
        for(int i=1;i<=n;++i)
            C[B[i]]=i;
        // cout<<"\n";
        for(int i=1;i<=n;++i)
            cout<<C[i]<<' ';
        cout<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
