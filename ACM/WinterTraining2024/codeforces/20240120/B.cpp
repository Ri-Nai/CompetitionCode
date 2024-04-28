#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n,m;
    int L[N];
    priority_queue<int>Q[N];
    set<int>S;
    ll sum[N];
    ll ansx,ansy;
    ll gcd(ll a,ll b)
    {
        return b?gcd(b,a%b):a;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=m;++i)
            cin>>L[i],sum[i]=0;
        for(int i=1;i<=n;++i)
        {
            int a,b;
            cin>>a>>b;
            Q[b].push(a);
            S.insert(b);
        }
        ansx=0;
        ansy=1;
        ll can=0;
        for(int i=1;i<=n;++i)
        {
            vector<int>Del;
            for(auto it=S.begin();it!=S.end();++it)
            {
                int p=*it;
                int x=Q[p].top();
                Q[p].pop();
                if(Q[p].empty())Del.push_back(p);
                if(L[p]==i)can+=sum[p];
                if(i>=L[p])can+=x;
                sum[p]+=x;
            }
            for(int p:Del)S.erase(p);
            if(can*ansy>ansx*i)ansx=can,ansy=i;
        }
        ll g=gcd(ansx,ansy);
        cout<<ansx/g<<'/'<<ansy/g<<'\n';
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
