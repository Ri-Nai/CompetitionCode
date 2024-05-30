#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pr;
#define End(X) return cout<<X<<'\n',void()
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
    const int N=1e5+5;
    int n,m;
    char s1[N],s2[N];
    typedef unsigned long long ull;
    const int P=19260817;
    ull S1L[N],S1R[N],S2[N],pow[N];
    ull Hash(ull *H,int l,int r)
    {
        return H[r]-H[l-1]*pow[r-l+1];
    }
    bool check(int l,int r)
    {
        int len=r-l+1;
        return Hash(S1L,l,l+(len-1)/2)==Hash(S1R,n-r+1,n-r+1+(len-1)/2);
    }
    void solve()
    {
        n=rd(),m=rd();
        cin>>s1+1>>s2+1;
        if(m<n)swap(n,m),swap(s1,s2);
        for(int i=1;i<=n;++i)
            S1L[i]=(S1L[i-1]*P+s1[i]);
        for(int i=1;i<=n;++i)
            S1R[i]=(S1R[i-1]*P+s1[n-i+1]);
        for(int i=1;i<=m;++i)
            S2[i]=(S2[i-1]*P+s2[i]);
        pow[0]=1;
        for(int i=1;i<=m;++i)
            pow[i]=pow[i-1]*P;
        int now=-1e9,ans=-1;
        for(int i=1;i<=n;++i)
        {
            if(check(i,n) and Hash(S1L,i,n)==Hash(S2,1,n-i+1))
                ans=max(ans,now+n-i+1);
            if(check(1,i) and Hash(S1L,1,i)==Hash(S2,m-i+1,m))
                now=i;
        }
        if(ans==-1)End("-1");
        cout<<ans*2<<'\n';

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
