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
        int n;cin>>n;
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(n&1)
        {
            if(t<=s)
                cout<<t<<'\n';
            else cout<<s+t<<'\n';
        }
        else
        {
            if(t<s)
                cout<<t+s<<'\n';
            else cout<<s<<'\n';
        }
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
