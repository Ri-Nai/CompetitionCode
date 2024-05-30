#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=105;
    int n,m;
    struct Stone
    {
        int val,wgh;
        void input()
        {
            cin>>val>>wgh;
        }
    }P[N][6];
    int ans[32][N];
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<5;++j)
                P[i][j].input();
            cin>>P[i][5].wgh;
        }
        // cout<<P[1][4].wgh<<'\n';
        int res=0;
        for(int w=m;w>=0;--w)
        {
            for(int i=0;i<32;++i)
            {
                res=max(res,ans[i][w]);
                for(int j=i+1;j<32;++j)
                {
                    if((i|j)!=j)continue;
                    int now=i^j;
                    // cout<<i<<' '<<j<<'\n';
                    if(now==(now&-now))
                        for(int p=0;p<5;++p)
                            if((1<<p)==now)
                                for(int k=1;k<=n;++k)
                                {
                                    int lst=w-P[k][p].wgh;
                                    if(lst>=0)
                                        ans[j][lst]=max(ans[j][lst],ans[i][w]+P[k][p].val);
                                }
                    for(int k=1;k<=n;++k)
                    {
                        int lst=w-P[k][5].wgh;
                        if(lst>=0)
                        {
                            int val=0;
                            for(int p=0;p<5;++p)
                                if((1<<p)&now)val+=P[k][p].val;
                            ans[j][lst]=max(ans[j][lst],ans[i][w]+val);
                        }
                    }
                }
            }
        }
        cout<<res<<'\n';
    }
}
bool Ri;
int main()
{
    // cout<<(&Ri-&Nai)/8.0/1024/1024<<'\n';
    ios::sync_with_stdio(0);
    // int t;cin>>t;while(t--)
    T::solve();

}
