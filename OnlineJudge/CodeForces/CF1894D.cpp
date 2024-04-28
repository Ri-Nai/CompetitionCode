#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,m;
    int A[N],B[N];
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=m;++i)cin>>B[i];
        sort(B+1,B+m+1);
        // int p=-1;
        // for(int i=m;i>=1;--i)
        // {
        //     if(B[i]<=A[1]){p=i;break;}
        //     cout<<B[i]<<' ';
        // }
        // for(int i=1;i<=n;++i)
        //     cout<<A[i]<<' ';
        // for(int i=1;i<=p;++i)
        //     cout<<B[i]<<' ';
        // cout<<'\n';
        int j=m;
        for(int i=1;i<=n;++i)
        {
            while(j>=1 and B[j]>=A[i])cout<<B[j--]<<' ';
            cout<<A[i]<<' ';
        }
        while(j>=1)cout<<B[j--]<<' ';
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
