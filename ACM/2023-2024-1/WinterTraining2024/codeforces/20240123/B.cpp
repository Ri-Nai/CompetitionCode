#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void solve()
    {
        int a,b,k;
        cin>>a>>b>>k;
        vector<int>ans;
        ans.push_back(a/b);
        a%=b;
        for(int i=1;i<=k+1;++i)
        {
            a*=10;
            ans.push_back(a/b);
            a%=b;
        }
        if(ans.back()>=5)++ans[ans.size()-2];
        int p=ans.size()-2;
        while(p>0 and ans[p]==10)
            --ans[p],++ans[p-1];
        cout<<ans[0]<<'.';
        for(int i=1;i<=ans.size()-2;++i)
            cout<<ans[i];
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
