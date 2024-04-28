#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    string s;
    void solve()
    {
        cin>>n>>s;
        vector<int>E;
        for(int i=s.size()-1;i>=0;)
        {
            if(s[i]=='b' or s[i]=='c' or s[i]=='d')
                E.push_back(i-3),i-=3;
            else E.push_back(i-2),i-=2;
        }
        int j=E.size()-2;
        for(int i=0;i<s.size();++i)
        {
            cout<<s[i];
            if(j>=0 and i==E[j])
            {
                --j;
                cout<<'.';
            }
        }
        cout<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
