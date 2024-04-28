#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=103;
    int n;
    int A[N],B[N],ans[N];
    void solve()
    {
        cin>>n;
        memset(B,0,sizeof B);
        for(int i=1;i<=n;++i)cin>>A[i],++B[A[i]];
        int cnt=0;
        for(int i=1;i<=100;++i)
            if(B[i]>=2)++cnt;
        if(cnt<=1)End("-1");
        bool flag1=0;
        for(int i=1;i<=100;++i)
        {
            bool flag2=0;
            for(int j=1;j<=n;++j)
            {
                if(A[j]==i)
                {
                    ans[j]=flag1+flag2+1;
                    flag2=1;
                }
            }
            if(B[i]>=2)flag1=1;
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<' ';
        cout<<'\n';
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
