#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n;
        string s;
        cin>>n>>s;
        int ans1=0,ans2=0;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                for(int k=j+1;k<n;++k)
                    if(s[i]=='d' and s[j]=='f' and s[k]=='s')ans2=1;
                    else if(s[i]=='D' and s[j]=='F' and s[k]=='S')ans1=1;
        cout<<ans1<<' '<<ans2<<'\n';
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
