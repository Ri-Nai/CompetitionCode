#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
ll rd()
{
    ll res=0,f=1;char c;
    do c=getchar(),c=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    map<int,int>mp;
    void solve()
    {
        // freopen("111.out","w",stdout);
        int n=rd(),m=rd();
        vector<ll>A;
        for(int i=1;i<=n;++i)A.push_back(rd());
        sort(A.begin(),A.end());
        for(int i=n-1;i>=0;--i)A[i]-=A[0];
        // cout<<A[0]<<' '<<A[1]<<'\n';
        for(int i=0;i<n;++i)
        {
            for(ll flag=1,y=A[i]+1;flag;++y)
            {
                ll S=1;
                if(i+1<n and A[i+1]-y<=0)break;
                for(int j=0;flag&&j<n;++j)
                {
                    S*=(A[j]-y);
                    if(S>1e9 or S<-1e9)flag=0;
                }
                if(flag)mp[(int)S]=1;
            }
            for(ll flag=1,y=A[i]-1;flag;--y)
            {
                ll S=1;
                if(i and A[i-1]-y>=0)break;
                for(int j=0;flag&&j<n;++j)
                {
                    S*=(A[j]-y);
                    if(S>1e9 or S<-1e9)flag=0;
                }
                if(flag)mp[(int)S]=1;
            }
        }
        for(ll x=1,flag=1;flag;++x)
        {
            ll S=1;
            for(int i=0;flag&&i<n;++i)
            {
                S*=A[i]+x;
                if(S>1e9 or S<-1e9)flag=0;
            }
            if(flag)mp[(int)S]=1;
        }
        for(int i=1;i<=m;++i)
        {
            int x=rd();
            if(x==0)cout<<"Yes\n";
            else cout<<(mp[x]?"Yes\n":"No\n");
        }

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
