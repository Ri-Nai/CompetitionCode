#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Point
{
    int x,y;
    void input()
    {
        // cin>>x>>y;
        scanf("%d%d",&x,&y);
    }
    double dis(Point _)
    {
        return sqrt((x-_.x)*(x-_.x)+(y-_.y)*(y-_.y));
    }
}P[N];
int n;
void Solve()
{
    cin>>n;
    double ans=1e18;
    for(int i=1;i<=n;++i)P[i].input();
    for(int i=1;i<=n;++i)
    {
        double now=0;
        for(int j=1;j<=n;++j)
        {
            now+=P[i].dis(P[j]);
        }
        ans=min(ans,now);
    }
    printf("%.10lf\n",ans/(n-1));
}
int main()
{
    // ios::sync_with_stdio(0);
    Solve();
}
