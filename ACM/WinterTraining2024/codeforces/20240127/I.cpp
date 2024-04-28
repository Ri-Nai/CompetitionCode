#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=1e6+5;
    int ans[N];
    int rd()
    {
        int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
        while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
        return f?-t:t;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<n;++i)
        {
            int u=rd(),v=rd(),w=rd();
            ans[u]^=w;
            ans[v]^=w;
        }
        for(int i=1;i<=m;++i)
        {
            int op,u,v,w;
            // cin>>op;
            op=rd();
            if(op==1)
            {
                u=rd();
                v=rd();
                w=rd();
                ans[u]^=w;
                ans[v]^=w;
            }
            else
                printf("%d\n",ans[rd()]);
                // cout<<ans[rd()]<<"\n";
        }
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
