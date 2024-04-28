#include<bits/stdc++.h>
using namespace std;
namespace T
{
    const int M=2e5+5;
    const int N=1e6+5;
    struct Pr
    {
        int val,pos;
        bool operator <(const Pr&_)const
        {
            return val<_.val;
        }
    }P[N];
    int L[M];
    int n,m,tot;
    void Solve()
    {
        cin>>n>>m;
        for(int i=1,t;i<=n;++i)
        {
            cin>>t;
            while(t--)
            {
                cin>>P[++tot].val;
                P[tot].pos=i;
            }
        }
        sort(P+1,P+tot+1);
        int now=0,res=0;
        for(int i=1;i<=tot;++i)
        {
            if(P[i].pos>L[now])
            {
                L[++now]=P[i].pos;
                if(now==m)L[now=0]=0,++res;
            }
            else *lower_bound(L+1,L+now+1,P[i].pos)=P[i].pos;
        }
        cout<<res<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    T::Solve();
}
