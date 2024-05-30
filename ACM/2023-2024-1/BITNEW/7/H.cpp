#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    string S[4]={"dong","xi","nan","bei"};
    int n;
    set<string>Str;
    void solve()
    {
        string whr;
        cin>>whr;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            string tmp;
            cin>>tmp;
            Str.insert(tmp);
        }
        int T;
        cin>>T;
        for(int i=0;i<T;++i)
        {
            string tmp;
            cin>>tmp;
            if(Str.find(tmp)!=Str.end())
            {
                if(S[i%4]==whr)End("zimo!");
                else End(S[i%4]);
            }
        }
        End("gan");
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
