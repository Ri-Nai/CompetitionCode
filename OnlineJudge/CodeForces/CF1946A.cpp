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
        vector<int>E;
        int n=rd();
        int mid=(n+1)>>1;
        for(int i=1;i<=n;++i)
            E.push_back(rd());
        sort(E.begin(),E.end());
        --mid;
        int ans=0;
        // for(int x:E)ans+=E[mid]==x;
        for(int i=mid;i<n;++i)ans+=E[i]==E[mid];
        printf("%d\n",ans);
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
