#include<queue>
#include<cstdio>
#include<algorithm>
#define pr std::pair<int,int>
#define mp std::make_pair
int const maxn=100;
int n,h,k,d[maxn],t[maxn],f[maxn],ans;
int main()
{
    std::priority_queue<pr>Q;
    scanf("%d%d",&n,&h);h*=12;
    for(int i=1;i<=n;++i)scanf("%d",&f[i]);
    for(int i=1;i<=n;++i)scanf("%d",&d[i]);
    for(int i=2;i<=n;++i)scanf("%d",&t[i]);
    for(int i=1;i<=n;++i)
    {
        int now=0;h-=t[i];
        while(!Q.empty())Q.pop();
        for(int j=1;j<=i;++j)Q.push(mp(f[j],j));
        for(int j=1;j<=h;++j)
        {
            int val=Q.top().first,id=Q.top().second;
            Q.pop();if(val>0)now+=val;
            Q.push(mp(val-d[id],id));
        }
        ans=std::max(ans,now);
    }
    printf("%d\n",ans);
} 