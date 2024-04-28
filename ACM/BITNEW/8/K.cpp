#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
bool Nai;
namespace T
{
    const int N=3005;
    int n;
    double X[N],Y[N];
    double dis(double x1,double y1,double x2,double y2)
    {
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    void solve()
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%lf%lf",&X[i],&Y[i]);
        double ans=1e18;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
            {
                double now=dis(0,0,X[i],Y[i])+dis(X[i],Y[i],X[j],Y[j])+dis(X[j],Y[j],0,0);
                if(now<ans)ans=now;
            }
        printf("%.6f\n",ans);
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
