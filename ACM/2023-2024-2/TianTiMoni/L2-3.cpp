#include<bits/stdc++.h>
using namespace std;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(res<<1)+(res<<3)+(c^48),c=getchar();
    return res*f;
}
namespace T
{
    const int N=1e7+5;
    bool mark[N];
    void Solve()
    {
        int n;
        long long m;
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(!mark[i])
            {
                int t=sqrt(m/i);
                for(int j=1;1ll*j*j*i<=n;++j)
                {
                    int now=j*j*i;
                    if(t&1)--ans;
                    else ++ans;
                    mark[now]=1;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    T::Solve();
}
