#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n,m;
    const int N=55;
    // int A[N],B[N];
    void solve()
    {
        cin>>n>>m;
        queue<int>A,B;
        for(int i=1,x;i<=n;++i)cin>>x,A.push(x);
        for(int i=1,y;i<=m;++i)cin>>y,B.push(y);
        while(!A.empty() and !B.empty())
        {
            int u=A.front(),v=B.front();
            A.pop();
            B.pop();
            int x=u-v,y=v-u;
            if(x>0)A.push(x);
            if(y>0)B.push(y);
        }
        if(A.empty() and B.empty())cout<<"Draw\n";
        else if(A.empty())cout<<"Tenzing\n";
        else cout<<"Tsondu\n";
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
