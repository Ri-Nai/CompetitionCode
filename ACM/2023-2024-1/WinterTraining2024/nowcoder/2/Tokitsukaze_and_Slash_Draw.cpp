#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
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
        int n=rd(),m=rd(),k=rd();
        k=n+1-k;
        vector<ll>val(n+1,1e18);
        vector<ll>ans(n+1,1e18);
        vector<int>in(n+1);
        queue<int>Q;
        ans[k]=0;
        for(int i=1;i<=m;++i)
        {
            int a=rd(),b=rd();
            a%=n;
            val[a]=min(val[a],0ll+b);
            if(!in[a])in[a]=1,Q.push(a);
        }
        while(!Q.empty())
        {
            int i=Q.front();
            Q.pop();
            in[i]=1;
            vector<int>vis(n+1);
            for(ll j=i+i;j<1ll*i*n;j+=i)
            {
                int k=j%n;
                if(vis[k])continue;
                ll now=val[i]*j/i;
                vis[k]=1;
                if(val[k]>now)
                {
                    if(!in[k])in[k]=1,Q.push(k);
                    val[k]=now;
                }
            }
        }
        for(int i=1;i<n;++i)
        {
            vector<ll>pre=ans;
            for(int j=1;j<=n;++j)
            {
                int from=(j+i-1)%n+1;
                ans[j]=min(ans[j],pre[from]+val[i]);
            }
        }
        if(ans[1]==ans[0])cout<<"-1\n";
        else cout<<ans[1]<<'\n';
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
