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
        long long ans=0;
        vector<int>A;
        for(int i=1;i<=n;++i)
            A.push_back(rd());
        sort(A.begin(),A.end());
        ans+=1ll*(n-1)*A[0];
        ll now=A[0];
        for(int i=1;i<n;++i)
        {
            ans+=now+1ll*(n-1-i)*min(A[0]*2,A[i]);
            now+=min(A[0]*2,A[i]);
        }
        //2*A[0] A[j] A[i]
        cout<<ans*2<<'\n';
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
