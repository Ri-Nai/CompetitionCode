#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1505;
    int A[N][N],B[N][N];
    int n,m;
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>A[j][i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>B[j][i];
        vector<int>ans;
        for(int i=1;i<=m;++i)
        {
            bool flag=1;
            for(int j=1;flag&&j<=n;++j)
                flag&=A[i][j]==B[i][j];
            if(!flag)
            {
                sort(A[i]+1,A[i]+n+1);
                flag=1;
                for(int j=1;flag&&j<=n;++j)
                    flag&=A[i][j]==B[i][j];
                if(!flag)End(-1);
                ans.push_back(i);
            }
        }
        cout<<ans.size()<<'\n';
        for(int x:ans)cout<<x<<' ';
        cout<<'\n';
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
