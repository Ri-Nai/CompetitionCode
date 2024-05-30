#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=105;
    int n,T[N];
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>T[i];
        int cnt=0;
        while(1)
        {
            int now=0;
            bool flag=0;
            for(int i=0;i<=n+1;++i)
            {
                if(now and !T[i])
                {
                    ++cnt;
                    now=0;
                }
                else if(!now and T[i])
                {
                    flag=1;
                    now=1;
                }
                if(T[i])--T[i];
            }
            if(!flag)break;
        }
        cout<<cnt<<'\n';
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
