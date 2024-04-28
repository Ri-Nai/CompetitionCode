#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do c=getchar(),f=c=='-'?-1:1;while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd();
        vector<int>cnt(105);
        for(int i=1;i<=n;++i)
        {
            int x=rd(),y=rd(),r=rd();
            ++cnt[r];
        }
        for(int i=1;i<=100;++i)
            cnt[i]+=cnt[i-1];
        if(cnt[50]>=n/10*9)cout<<"bit-noob\n";
        else cout<<"buaa-noob\n";
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
