#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>res;
        int now=0;
        for(char c:s)
        {
            int x=c^48;
            if(res.empty() and !x)continue;
            now+=x;res.push_back(now);
        }
        if(res.empty())res.push_back(0);
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();++i)
        {
            int k=res[i]/10;
            if(k and i==res.size()-1)
                res.push_back(0);
            if(k)res[i+1]+=k;
            res[i]%=10;
        }
        reverse(res.begin(),res.end());
        for(int x:res)cout<<x;
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
