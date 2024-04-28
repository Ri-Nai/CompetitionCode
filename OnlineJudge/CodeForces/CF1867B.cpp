#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=2e5+5;
    char s[M];
    int n,mark[M];
    void solve()
    {
        cin>>n>>s+1;
        for(int i=0;i<=n;++i)mark[i]=0;
        int p=0,q=0;
        for(int i=1,j=n;i<j;++i,--j)
            p+=s[i]^s[j];
        q=n/2-p;
        for(int i=p;q>=0;i+=2,--q)
        {
            mark[i]=1;
            if(n%2)mark[i+1]=1;
        }
        for(int i=0;i<=n;++i)
            cout<<mark[i];
        cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();
}
