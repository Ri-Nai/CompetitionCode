#include<queue>
#include<cstdio>
#include<algorithm>
int n,T,t[10005],pos[10005];
int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;++i)scanf("%d",&t[i]);
    for(int i=1;i<=n;++i)scanf("%d",&pos[i]);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int sum=0;
		std::priority_queue<int>Q;
        for(int j=i;j<=n;++j)
        {
            Q.push(t[j]),sum+=t[j];
            while(!Q.empty()&&sum+std::abs(pos[j]-pos[i])>T)
                sum-=Q.top(),Q.pop();
            if(Q.size()>ans)ans=Q.size();
        }
    }
    printf("%d\n",ans);
}