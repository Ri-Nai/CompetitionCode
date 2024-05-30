#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=10;
    int n,m;
    string s[N];
    int pos[N];
    bool mark[N];
    bool flag;
    bool check(string a,string b)
    {
        int cnt=0;
        for(int i=0;i<a.size();++i)
            cnt+=a[i]!=b[i];
        return cnt==1;
    }
    void dfs(int x)
    {
        if(flag)return;
        if(x==n+1)
        {
            flag=1;
            return;
        }
        for(int i=1;i<=n;++i)
        {
            if(mark[i])continue;
            if(x==1 || check(s[i],s[pos[x-1]]))
            {
                mark[i]=1;
                pos[x]=i;
                dfs(x+1);
                mark[i]=0;

            }
        }
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>s[i];
        dfs(1);
        cout<<(flag?"Yes":"No")<<"\n";
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
