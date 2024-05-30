#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    int n;
    void solve()
    {
        cin>>n;
        bool p[]={0,0,0,0};
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x>0)p[0]=1;
            if(x<0)p[1]=1;
            if(y>0)p[2]=1;
            if(y<0)p[3]=1;
        }
        int cnt=p[0]+p[1]+p[2]+p[3];
        if(cnt==4)cout<<"NO\n";
        else cout<<"YES\n";
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
