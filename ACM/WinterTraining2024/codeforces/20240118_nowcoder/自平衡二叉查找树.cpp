#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int n,Q;
    ll ans[N];
    struct Pr
    {
        int t,m,d;
        bool operator <(const Pr &_)const
        {
            if(t==_.t)
            {
                if(m==_.m)return d<_.d;
                return m>_.m;
            }
            return t>_.t;
        }
    };
    void solve()
    {
        cin>>n>>Q;
        priority_queue<Pr>QT;
        set<int>S;
        for(int i=1;i<=n;++i)S.insert(i);
        for(int i=1;i<=Q;++i)
        {
            int t,m,d;
            cin>>t>>m>>d;
            QT.push((Pr){t,m,d});
        }
        while(!QT.empty())
        {
            Pr p=QT.top();
            QT.pop();
            if(p.m)
            {
                if(S.empty())continue;
                auto it=S.begin();
                ans[*it]+=p.m;
                QT.push((Pr){p.t+p.d,0,*it});
                S.erase(it);
            }
            else
                S.insert(p.d);
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<'\n';
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
