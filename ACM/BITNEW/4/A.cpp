#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
namespace T
{
    const int N=1e5+5;
    struct Seg
    {
        int l,r,id;
        void input(int i)
        {
            cin>>l>>r;
            id=i;
        }
        bool operator <(const Seg &_)const
        {
            if(l==_.l)return id<_.id;
            return l<_.l;
        }
    }P[N],Q[N];
    bool cmp(Seg s1,Seg s2)
    {
        return s1.r<s2.r;
    }
    int n,m;
    set<Seg>S;
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)P[i].input(i),Q[i]=P[i],S.insert(P[i]);
        sort(P+1,P+n+1,cmp);
        int now=1,ans=0;
        cin>>m;
        for(int x;m--;)
        {
            cin>>x;
            while(now<=n and P[now].r<x)
            {
                auto it=S.find(P[now]);
                if(it!=S.end())S.erase(it);
                ++now;
            }
            // auto tt=S.begin();
            // cout<<"****\n";
            // while(tt!=S.end())cout<<tt->l<<' '<<tt->r<<' '<<tt->id<<'\n',++tt;
            auto it=S.begin();
            while(it!=S.end() and it->l<=x)
            {
                S.erase(it),++ans;
                it=S.begin();
            }
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();
}
