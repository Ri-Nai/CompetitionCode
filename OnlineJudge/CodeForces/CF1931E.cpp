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
        int n=rd(),m=rd();
        vector<Pr>E;
        for(int i=1;i<=n;++i)
        {
            int x=rd();
            int p=0,q=0;
            while(x%10==0)++p,x/=10;
            while(x)++q,x/=10;
            E.push_back({p,q});
        }
        sort(E.begin(),E.end(),greater<Pr>());
        bool flag=1;
        int res=0;
        for(auto [x,y]:E)
        {
            if(flag)res+=y;
            else res+=x+y;
            flag^=1;
        }
        End((res>m)?"Sasha":"Anna");
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
