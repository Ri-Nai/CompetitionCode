#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<(X)<<'\n',void()
bool Nai;
int rd()
{
    int res=0,f=1;char c;
    do (c=getchar())=='-'&&(f=-1);while(!isdigit(c));
    while(isdigit(c))res=(c^48)+(res<<1)+(res<<3),c=getchar();
    return res*f;
}
namespace T
{
    void solve()
    {
        int n=rd();
        vector<int>A(n+1);
        int m=0;
        for(int i=1;i<=n;++i)
        {
            int x=rd();
            A[i]=x;
            m=max(m,x);
        }
        vector<ll>ans(m+1);
        auto Add=[&](int x,int y)
        {
            while(x<=m)ans[x]+=y,x+=x&-x;
        };
        auto Sum=[&](int x)
        {
            ll res=0;
            while(x)res+=ans[x],x-=x&-x;
            return res;
        };
        auto get=[](int a,int b,int c)
        {
            return (a+c-1)/c-(b+c-1)/c;
        };
        for(int i=1;i<=n;++i)
        {
            if(A[i]>A[i-1])
            {
                vector<int>X,Y,E;
                auto PB=[&](vector<int>&T,int x)
                {
                    if(!x)return;
                    --x;
                    for(int i=1;i<=x;++i)
                    {
                        T.push_back(i);
                        i=x/(x/i);
                    }
                    T.push_back(x+1);
                };
                PB(X,A[i]);
                PB(Y,A[i-1]);
                int a=0,b=0;
                while(a<X.size() || b<Y.size())
                    if(b>=Y.size() ||a<X.size() && X[a]<Y[b])E.push_back(X[a++]);
                    else E.push_back(Y[b++]);
                E.erase(unique(E.begin(),E.end()),E.end());
                int last=0;
                for(int j:E)
                {
                    Add(j,-last);
                    Add(j,last=get(A[i],A[i-1],j));
                }
            }
        }
        for(int i=1;i<=m;++i)
            cout<<Sum(i)<<" \n"[i==m];
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
