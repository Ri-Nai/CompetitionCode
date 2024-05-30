#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1005;
    int n,m,l[N];
    struct Pr
    {
        int S,P,x,y;
        void input(int _,int __)
        {
            cin>>S>>P;
            x=_,y=__;
        }
        bool operator <(const Pr &_)const
        {
            return S<_.S;
        }
    }A[N][N];
    vector<Pr>E;
    multiset<int>M[N];
    void solve()
    {
        cin>>n>>m;
        ll now=0;
        for(int i=1;i<=n;++i)
        {
            l[i]=1;
            for(int j=1;j<=m;++j)
            {
                A[i][j].input(i,j);
                M[i].insert(A[i][j].P);
            }
            sort(A[i]+1,A[i]+m+1);
        }
        ll ans1=0,ans2=1;
        for(int i=1;i<=n;++i)ans1+=*M[i].begin();
        for(int i=2;i<=1000;++i)
        {
            ll now=0;
            for(int j=1;j<=n;++j)
            {
                while(l[j]<=m and A[j][l[j]].S<i)
                    M[j].erase(M[j].find(A[j][l[j]++].P));
                if(l[j]==m+1)End(ans1);
                now+=*M[j].begin();
            }
            if(now*ans2<ans1*i)
                ans1=now,ans2=i;
        }
        cout<<ans1<<'\n';
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
