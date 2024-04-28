#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void solve()
    {
        int n,k;
        cin>>n>>k;
        vector<int>ans;
        for(int i=1;i<=k;++i)
            for(int j=i;j<=n;j+=k)
                ans.push_back(j);
        for(int i=0;i<ans.size();++i)
            cout<<ans[i]<<" \n"[i==ans.size()-1];
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
