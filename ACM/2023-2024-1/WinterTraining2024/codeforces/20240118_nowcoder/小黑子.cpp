#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    void solve()
    {
        string s;
        cin>>s;
        for(int i=0;i<s.size();++i)
            s[i]=tolower(s[i]);
        for(int i=0;i<s.size()-3;++i)
        {
            if(s[i]=='j' and s[i+1]=='n' and s[i+2]=='t' and s[i+3]=='m')
            {
                cout<<"yes\n";
                return;
            }
        }
        cout<<"no";
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
