#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=2e5+5;
    int n;
    // char S[N][6];
    int len[N];
    string S[N];
    map<int,int>cnt1[6],cnt2[6];
    bool cmp(string S1,string S2)
    {
        return S1.size()>S2.size();
    }
    void solve()
    {
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            // cin>>S[i]+1;
            cin>>S[i];
        }
        sort(S+1,S+n+1,cmp);
        for(int i=1;i<=n;++i)
        {
            int num=0;
            int now=S[i].size();
            for(int j=0;j<S[i].size();++j)
                num+=S[i][j]^48;
            for(int j=0;j<S[i].size();++j)
            {
                if(now<0)break;
                ++cnt1[now][num];
                num-=2*(S[i][j]^48);
                now-=2;
            }
            now=S[i].size();
            num=0;
            for(int j=0;j<S[i].size();++j)
                num+=S[i][j]^48;
            for(int j=S[i].size()-1;j>=0;--j)
            {
                if(now<0)break;
                ++cnt2[now][num];
                num-=2*(S[i][j]^48);
                now-=2;
            }
            num=0,now=S[i].size();
            for(int j=0;j<S[i].size();++j)
                num+=S[i][j]^48;
            ans+=cnt1[S[i].size()][num];
            ans+=cnt2[S[i].size()][num];
            --ans;
        }
        // for(int i=0;i<=5;++i)
        // {
            // cout<<i<<' '<<cnt[i]<<'\n'
        //     cout<<i<<'\n';
        //     for(auto t:cnt[i])
        //         cout<<t.first<<' '<<t.second<<'\n';
        // }

        // for(int i=1;i<=n;++i)
        // {
        //     int num=0,now=S[i].size();
        //     for(int j=0;j<S[i].size();++j)
        //         num+=S[i][j]^48;
        //     ans+=cnt[S[i].size()][num];
        // }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
