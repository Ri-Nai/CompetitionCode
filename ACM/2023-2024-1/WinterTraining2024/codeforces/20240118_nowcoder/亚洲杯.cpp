#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int A[N],num[N];
    int rk[N];
    int n,R;
    bool cmp(int a,int b)
    {
        if(num[a]==num[b])return a<b;
        return num[a]>num[b];
    }
    void solve()
    {
        cin>>n>>R;
        n<<=1;
        for(int i=1;i<=n;++i)
        {
            rk[i]=i;
            cin>>A[i];
        }
        while(R--)
        {
            for(int i=1;i<=n;i+=2)
            {
                int x=rk[i],y=rk[i+1];
                if(A[x]>A[y])num[x]+=3;
                else num[y]+=3;
            }
            sort(rk+1,rk+n+1,cmp);
        }
        for(int i=1;i<=n;++i)
            if(rk[i]==1)cout<<i<<'\n';
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
