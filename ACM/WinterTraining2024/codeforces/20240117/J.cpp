#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const ll len=1e9+1;
    const int N=1e6+5;
    int n,l,r;
    int A[N],D[N];
    long long ans=0;
    void solve()
    {
        cin>>n>>l>>r;
        int mn=min(l,r);
        int t=mn/n;
        ans=len*t*2;
        l-=t*n;
        r-=t*n;
        queue<int>L,R;
        for(int i=1;i<=n;++i)cin>>A[i];
        for(int i=1;i<=n;++i)cin>>D[i];
        for(int i=n;i>=1;--i)
            if(D[i])R.push(A[i]);
        for(int i=1;i<=n;++i)
            if(!D[i])L.push(A[i]);
        while(1)
        {
            int tnow=0;
            vector<int>NL,NR;
            while(!L.empty() and !R.empty())
            {
                int p=L.front();
                int q=R.front();
                // cout<<p<<' '<<q<<'\n';
                int tp=p,tq=len-q;
                if(tp<tq)
                {
                    L.pop();
                    tnow=tp;
                    if(l>0)--l,NR.push_back(len-tp);
                }
                else
                {
                    R.pop();
                    tnow=tq;
                    if(r>0)--r,NL.push_back(tq);
                }
            }
            while(!L.empty())
            {
                int p=L.front();
                L.pop();
                int tp=p;
                tnow=tp;
                if(l>0)--l,NR.push_back(len-tp);
            }
            while(!R.empty())
            {
                int q=R.front();
                R.pop();
                int tq=len-q;
                tnow=tq;
                if(r>0)--r,NL.push_back(tq);
            }
            if(NL.empty() and NR.empty())
            {
                ans+=tnow;
                cout<<ans<<'\n';
                return ;
            }
            ans+=len;
            for(int p:NL)L.push(p);
            for(int q:NR)R.push(q);
            NL.clear();
            NR.clear();
        }
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
