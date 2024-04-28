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
        int n=rd(),l=rd();
        vector<pair<int,int>>A(n+1);
        for(int i=1;i<=n;++i)
            A[i].second=rd(),A[i].first=rd();
        sort(A.begin()+1,A.end());
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int mx=0;
            ll sum=0;
            priority_queue<int>Q;
            for(int j=i;j<=n;++j)
            {
                Q.push(A[j].second);
                sum+=A[j].second;
                mx=A[j].first-A[i].first;
                while(!Q.empty()and sum+mx>l)
                {
                    sum-=Q.top();
                    Q.pop();
                }
                ans=max(ans,(int)Q.size());
            }
        }
        cout<<ans<<'\n';
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
