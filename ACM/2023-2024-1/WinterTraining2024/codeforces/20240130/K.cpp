#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    void solve()
    {
        int n,t;
        cin>>n>>t;
        vector<pair<int,int>>T;
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x<y)++cnt;
            else T.push_back({x,y});
        }
        sort(T.begin(),T.end());
        if(cnt>n/2)End("Make Byteland Great Again!");
        for(auto &[x,y]:T)
        {
            int k=(x-y+1)/2;
            if(t-k<0)break;
            t-=k;
            if(++cnt>n/2)End("Make Byteland Great Again!");
        }
        End("Fake Polls!");
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
