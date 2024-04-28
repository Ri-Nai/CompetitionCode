#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=2005;
    int n;
    ll A[N],dp[N][N];//dp[i][j]代表以i为结尾 以j为上个分割点的
    #define X(k) (A[k])
    #define Y(k) (dp[i][k])
    #define Slope(a,b) ((long double)(Y(a)-Y(b))/(X(a)-X(b)))
    #define Get(k,x) (Y(k)-(x)*X(k))
    struct TB
    {
        int stk[N],top,i;
        TB(){top=0,memset(stk,0,sizeof stk);}
        void insert(int p)
        {
            while(top>1 and Slope(stk[top-1],p)
            >=Slope(stk[top-1],stk[top]))--top;
            stk[++top]=p;
        }
        int Find(int x)
        {
            int l=2,r=top,res=1;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(Get(stk[mid],x)>Get(stk[mid-1],x))
                    res=mid,l=mid+1;
                else r=mid-1;
            }
            return stk[res];
        }
    }tb;
    struct Pr
    {
        int id,val;
        bool operator <(const Pr &_)const
        {
            if(val==_.val)return id<_.id;
            return val<_.val;
        }
    };
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>A[i],A[i]+=A[i-1];
        memset(dp,-0x3f,sizeof dp);
        for(int i=1;i<=n;++i)dp[i][0]=0;
        set<Pr>S;
        S.insert((Pr){0,0});
        for(int i=1;i<=n;++i)
        {
            // for(int j=1;j<i;++j)
            //     for(int k=0;k<j;++k)
            //         dp[i][j]=max(dp[i][j],dp[j][k]+(A[i]-A[j])*(A[j]-A[k]));
            //dp[j][k]-(A[i]-A[j])*A[k]+(A[i]-A[j])*A[i]
            /*
                // for(int j=0;j<i;++j)
                    // for(int k=i+1;k<=n;++k)

                for(int j=i+1;j<=n;++j)
                    for(int k=0;k<i;++k)
                        dp[j][i]=max(dp[j][i],dp[i][k]+(A[j]-A[i])*(A[i]-A[k]);
                        dp[i][k]-(A[j]-A[i])*A[k]-(A[i]-A[j])*A[i];
                为了维持凸包的X的单调性
                我们首先先从0~i-1把当前的凸包构建出来啊啊啊啊
            */
            tb.i=i;
            tb.top=0;
            for(auto P:S)tb.insert(P.id);//
            for(int j=i+1;j<=n;++j)
            {
                int p=tb.Find(A[j]-A[i]);
                dp[j][i]=Get(p,A[j]-A[i])-(A[i]-A[j])*A[i];
            }
            // tb[i].j=i;
            // tb[i].insert(0);
            // for(int j=1;j<i;++j)
            // {
            //     //把dp[i][j]求好之后放到i的凸包中
            //     //查询编号为j的凸包
            //     int p=tb[j].Find(A[i]-A[j]);
            //     dp[i][j]=Get(p,A[i]-A[j])+A[i]*A[j]-A[j]*A[j];
            //     tb[i].insert(j);
            // }
            S.insert((Pr){i,A[i]});
        }
        ll ans=-0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;++i)ans=max(ans,dp[n][i]);
        cout<<ans<<'\n';
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
