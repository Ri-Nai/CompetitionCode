#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=105;
    vector<int>A[2];
    bool mark[5005][2];
    bool ans[5005][2];
    bool win(int x,int p)
    {
        if(mark[x][p])return ans[x][p];
        mark[x][p]=1;
        bool now=0;
        for(int y:A[p])
        {
            if(y>x)break;
            now|=win(x-y,p^1)^1;
        }
        //有一个必败态就是必胜态
        //没有必败态就是必败态
        return ans[x][p]=now;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=0;i<=1;++i)
            for(int j=0,x;j<m;++j)
                cin>>x,A[i].push_back(x);
        cout<<(!win(n,0)?"Mao Mao":"Long Long")<<" nb!\n";
        // for(int i=1;i<=n;++i)cout<<i<<' '<<win(i,0)<<' '<<win(i,1)<<'\n';
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
