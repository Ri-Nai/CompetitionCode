#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        string s;
        cin>>s;
        int n=s.size();
        int t=n/2;
        int ans=0;
        for(int i=1;i<=t;++i)
        {
            int cnt=0;
            for(int j=0;j+i<n;++j)
            {
                if(s[j]==s[j+i] or s[j]=='?' or s[j+i]=='?')++cnt;
                if(j-i>=0)if(s[j]==s[j-i] or s[j]=='?' or s[j-i]=='?')--cnt;
                if(cnt==i)ans=max(ans,cnt);
            }
            // cout<<i<<' '<<cnt<<'\n';
        }
        printf("%d\n",ans*2);

    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
