#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=5e5+10;
    int A[N],B[N],C[N];
    int a,b,c,d;
    ll SL[N],SR[N];
    void Solve()
    {
        for(int i=1;i<=a;++i)cin>>A[i];
        for(int i=1;i<=b;++i)cin>>B[i];
        for(int i=1;i<=c;++i)cin>>C[i];
        for(int i=1;i<=a;++i)
        {
            int l=lower_bound(B+1,B+b+1,A[i]-d)-B;
            int r=upper_bound(B+1,B+b+1,A[i]+d)-B-1;
            SL[i]=SL[i-1]+l;
            SR[i]=SR[i-1]+r;
        }
        ll ans=0;
        for(int i=1;i<=c;++i)
        {
            int l=lower_bound(B+1,B+b+1,C[i]-d)-B;
            int r=upper_bound(B+1,B+b+1,C[i]+d)-B-1;
            //在B处的下标
            int L=lower_bound(A+1,A+a+1,C[i]-d)-A;
            int R=upper_bound(A+1,A+a+1,C[i]+d)-A-1;
            int ML=lower_bound(A+1,A+a+1,C[i])-A;
            int MR=upper_bound(A+1,A+a+1,C[i])-A-1;
            ans+=SR[ML-1]-SR[L-1]-1ll*(ML-L)*(l-1);
            ans+=1ll*(R-MR)*(r+1)-(SL[R]-SL[MR]);
            ans+=1ll*(MR-ML+1)*(r-l+1);
        }
        cout<<ans<<'\n';
    }
    void solve()
    {
        while(cin>>d>>a>>b>>c)Solve();
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
/*
求出对于每个左边界右边界
A数组在B数组的左右对吧
那我们
*/
