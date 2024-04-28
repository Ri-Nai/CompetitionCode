#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,A[N],now;
struct Point
{
    int u,w;
    bool operator <(const Point &_)const
    {
        return w>_.w;
    }
};
void Solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>A[i];
    priority_queue<Point>Q;
    m=min(n,m);
    int ans=0;
    for(int i=1;i<=m;++i)
        Q.push((Point){i,now+A[i]});
    int id=m+1;
    while(!Q.empty())
    {
        int t=Q.top().w;
        ans=max(ans,t-now);
        Q.pop();
        now=t;
        if(id<=n)Q.push((Point){0,now+A[id++]});
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    Solve();
}
