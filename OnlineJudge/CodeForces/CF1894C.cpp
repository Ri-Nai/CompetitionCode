#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2e5+5;
    int A[N],mark[N];
    int n;
    ll k;
    int stk[N],top;
    void solve()
    {
        cin>>n>>k;
        top=0;
        for(int i=1;i<=n;++i)
            cin>>A[i],mark[i]=0;
        int p=n;
        bool flag=0;
        while(!mark[p])
        {
            if(A[p]>n)
            {
                flag=1;
                break;
            }
            stk[++top]=A[p];
            mark[p]=1;
            p=(p-A[p]+n+n-1)%n+1;
        }
        ll sum=0,now=0;
        int tp=top;
        if(flag and top<k)End("No");
        End("Yes");
        if(flag)End("No");
        if(k%sum==0)End("Yes");
        End("No");
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
