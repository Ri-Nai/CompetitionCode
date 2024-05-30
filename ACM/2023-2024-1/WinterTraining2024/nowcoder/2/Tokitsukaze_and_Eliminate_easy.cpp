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
    void solve()
    {
        int n=rd();
        vector<int>A(n+1);
        for(int i=1;i<=n;++i)A[i]=rd();
        int ans=0,pos=n;
        int last=A[n];
        for(int i=n;i>=1;--i)
        {
            if(A[i]!=last)
            {
                ++ans;
                pos=i-1;
                last=A[i-1];
            }
        }
        cout<<ans+pos<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    // ios::sync_with_stdio(0);
    int t;cin>>t;while(t--)
    T::solve();

}
