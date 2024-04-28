#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
int B[40];
map<int,int>is;
void init()
{
    B[0]=1;is[1]=0;
    for(int i=1;i<31;++i)
        B[i]=B[i-1]<<1,is[B[i]]=i;
}
namespace T
{
    const int M=2e5+5;
    int n,A[M],mark[40],can[40];
    void solve()
    {
        cin>>n;
        ll sum=0;
        memset(mark,0,sizeof mark);
        memset(can,0,sizeof can);
        for(int i=1;i<=n;++i)
            cin>>A[i],sum+=A[i];
        if(sum%n)End("No");
        int ave=sum/n;
        for(int i=1;i<=n;++i)
        {
            bool flag=0;
            int t=ave-A[i];
            if(!t)continue;
            // if(t>0 and is.count(t))
            // {
            //     if(A[i]>=t)++can[is[t]];
            //     else ++mark[is[t]];
            //     flag=1;
            // }
            // else if(t<0 and is.count(-t))
            // {
            //     // cout<<i<<"*1\n";
            //     if(A[i]>=2*-t)--can[is[-t]];
            //     else --mark[is[-t]];
            //     flag=1;
            // }
            else
                for(int j=0;j<=30;++j)
                {
                    int x=t+B[j];
                    if(is.count(x))
                    {
                        flag=1;
                        ++mark[j],--mark[is[x]];
                        break;
                    }
                }
            if(!flag)End("No");
        }
        // cout<<"111"<<'\n';
        // for(int i=0;i<=30;++i)
        //     cout<<mark[i]<<' '<<can[i]<<'\n';
        // for(int i=0;i<=30;++i)
        // {
        //     int t=mark[i];
        //     if(abs(mark[i]+can[i])%2)End("No");
        //     if(abs(mark[i]+can[i])>abs(can[i])*2)End("No");
        //     if(can[i])mark[i]=0;
        //     mark[i+1]+=(mark[i]+can[i])/2;
        // }
        for(int i=0;i<=30;++i)
            if(mark[i])End("No");
            // cout<<mark[i]<<' '<<'\n';
            // if(mark[i])End("No");
        End("Yes");
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;while(t--)
    T::solve();

}
/*
1
6
18 7  17 8  18 16
14 14 14 14 14 14
-4 +8-1 +4-1 +8-2 -4 -2
-4-4-2

mark[i]+can[i]=0
can[i]-1 mark[i]-1
*/
