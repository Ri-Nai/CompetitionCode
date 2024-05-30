#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
ll rd()
{
    ll res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    int cnt[10];
    int one[10];
    int cnt0[10];
    int rest[10];
    void solve()
    {
        int n=rd();
        ll res=0;
        vector<ll>A;
        for(int i=0;i<n;++i)A.push_back(rd());
        sort(A.begin(),A.end());
        for(int i=0;i<n;++i)
        {
            ll x=A[i];
            if(x<10)
            {
                if(x==3)res+=one[6];
                if(x==7)res+=one[2];
                if(x==6)res+=one[3];
                if(x==2)res+=one[7];
                ++one[x];
                ++cnt[x%9];
            }
            else
            {
                res+=cnt0[8-(x-1)%9];
                if(!(x&3))
                {
                    res+=cnt[8-(x-1)%9];
                    ++cnt0[x%9];
                }
                if((x%10*10+(8-(x-1)%9))%4==0)
                    res+=one[8-(x-1)%9];
                ++cnt[x%9];
            }
        }
        cout<<res<<'\n';

    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
