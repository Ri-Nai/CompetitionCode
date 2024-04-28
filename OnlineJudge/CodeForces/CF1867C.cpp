#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
#define Out(X) printf("%d\n",X),fflush(stdout)
namespace T
{
    const int M=1e5+5;
    int n,s[M];
    void solve()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&s[i]);
        if(s[1]!=0)Out(0);
        else
        {
            bool flag=0;
            for(int i=2;i<=n;++i)
                if(s[i]-s[i-1]!=1)
                {
                    Out(s[i-1]+1);
                    flag=1;
                    break;
                }
            if(!flag)Out(s[n]+1);
        }
        while(1)
        {
            int y;
            scanf("%d",&y);
            if(y==-1)break;
            else if(y==-2)break;
            Out(y);
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    T::solve();

}
