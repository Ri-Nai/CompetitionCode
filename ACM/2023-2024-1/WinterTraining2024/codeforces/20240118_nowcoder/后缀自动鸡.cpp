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
        string s;
        long long m;
        cin>>n>>k>>m;
        cin>>s;
        if(k==1)
        {
            cout<<s<<'\n';
        }
        else
        {
            sort(s.begin(),s.end());
            for(int i=n-1;i>=0;--i)
                cout<<s[i];
            cout<<'\n';
        }
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
