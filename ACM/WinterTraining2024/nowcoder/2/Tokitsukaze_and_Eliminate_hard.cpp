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
        int n=rd();
        vector<int>A(n+1);
        map<int,int>vis,now;
        int tot=0;
        int cnt=0;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            A[i]=rd();
            tot+=!vis[A[i]];
            ++vis[A[i]];
        }
        int last=n;
        for(int i=n;i>=1;--i)
        {
            if(!now[A[i]])++cnt;
            ++now[A[i]];
            // cout<<tot<<' '<<cnt<<'\n';
            if(tot==cnt)
            {
                ++ans;
                // cout<<i<<'\n';
                // cout<<tot<<' '<<cnt<<'\n';
                cnt=0;
                for(int j=i;j<=last;++j)
                {
                    vis[A[j]]-=now[A[j]];
                    if(now[A[j]] and !vis[A[j]])--tot;
                    now[A[j]]=0;
                }
                // cout<<tot<<' '<<cnt<<'\n';
                last=i-1;
            }
        }
        cout<<ans<<'\n';
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
