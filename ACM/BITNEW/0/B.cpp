#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int M=105;
    char s[M];
    void solve()
    {
        cin>>s+1;
        int n=strlen(s+1);
        int cnt=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='0')--cnt;
            else ++cnt;
        if(cnt<0)End("evil longlong");
        else End("kind longlong");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
