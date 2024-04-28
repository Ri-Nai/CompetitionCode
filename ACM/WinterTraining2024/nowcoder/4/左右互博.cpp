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
    int can(int x)
    {
        if(x==1)return 0;
        if(x==2)return 1;
        for(int i=1;i<=x/2;++i)
        {
            int p=can(i)^can(x-i);
            if(!p)return 1;
        }
        return 0;
    }
    void solve()
    {
        int n=rd();
        int res=0;
        for(int i=1;i<=n;++i)
        {
            res^=rd()&1^1;
        }
        if(res)End("gui");
        else End("sweet");
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
