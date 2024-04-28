#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=1e5+5;
    int n;
    int A[N],B[N],C[N],D[N];
    int dis[N];
    ll Solve(int *L,int *R)
    {
        vector<int>PL,PR,Point;
        for(int i=1;i<=n;++i)
            PL.push_back(L[i]),
            PR.push_back(R[i]),
            Point.push_back(L[i]),
            Point.push_back(R[i]);

        sort(PL.begin(),PL.end());
        sort(PR.begin(),PR.end());
        sort(Point.begin(),Point.end());
        ll ldis=0,rdis=0;
        for(int i=1;i<=n;++i)
            rdis+=L[i];
        int lcnt=0,rcnt=n;
        //假设从0开始
        int pl=0,pr=0;
        int last=0;
        // cout<<ldis<<' '<<rdis<<'\n';
        ll ans=1e18;
        for(int x:Point)
        {
            // cout<<x<<'\n';
            rdis-=1ll*rcnt*(x-last);
            while(pl<PL.size() and x>=PL[pl])
            {
                ++pl;--rcnt;
            }
            // cout<<ldis+rdis<<'\n';
            while(pr<PR.size() and x>PR[pr])
            {
                ++pr;++lcnt;
            }
            ldis+=1ll*lcnt*(x-last);
            // cout<<x<<' '<<ldis<<' '<<rdis<<'\n';
            ans=min(ans,ldis+rdis);
            last=x;
        }
        return ans;

    }
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        cout<<Solve(A,C)+Solve(B,D)<<'\n';
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
