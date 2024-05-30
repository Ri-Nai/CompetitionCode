#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e3+3;
    int n,m;
    int R[N],L[N];
    int cnt[N];
    bool mark[N];
    int P[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>L[i]>>R[i];
        cin>>m;
        int pos=1;
        for(int i=1;i<=m;++i)
        {
            int x;cin>>x;
            pos=upper_bound(L+1,L+n+1,x)-L-1;
            if(pos==0)continue;
            if(x<=R[pos])++cnt[pos],P[pos]=x;
            if(R[pos-1]==x)++cnt[pos-1],P[pos-1]=x;
            if(x==L[pos] and x==R[pos-1])mark[pos-1]=1;
        }
        vector<int>ans;
        for(int i=1;i<=n;++i)
        {
            if(cnt[i]>2)
            {
                cout<<"impossible\n";
                return;
            }
            if(cnt[i]==2)continue;
            if(i!=n and cnt[i+1]<2 and R[i]==L[i+1] and !mark[i])
                ++cnt[i],++cnt[i+1],mark[i]=1,ans.push_back(P[i]=P[i+1]=R[i]);
            for(int j=L[i]+1;cnt[i]<2;++j)
            {
                if(j==P[i])continue;
                ++cnt[i];
                ans.push_back(j);
            }
        }
        cout<<ans.size()<<'\n';
        sort(ans.begin(),ans.end());
        for(int x:ans)cout<<x<<' ';
        cout<<'\n';

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
