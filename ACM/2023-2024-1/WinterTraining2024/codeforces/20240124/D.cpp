#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,t;
    const int N=105;
    set<int>S[N];
    void solve()
    {
        cin>>n>>t;
        S[1].insert(n+1);
        while(t--)
        {
            int x,y;
            cin>>x>>y;
            if(x==-1)x=n+1;
            if(y==-1)y=n+1;
            if(x==y)continue;
            for(int i:S[y])
                if(i!=x)S[x].insert(i);
        }
        int ans=0;
        vector<int>res;
        for(int i=1;i<=n;++i)
        {
            if(S[i].count(n+1))
                ans++,res.push_back(i);
        }
        cout<<ans<<'\n';
        for(int i:res)cout<<i<<' ';
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
