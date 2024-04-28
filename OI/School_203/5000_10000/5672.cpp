#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
const int maxn=1e5+5,inf=0x3f3f3f3f;
struct $
{
    int t1,t2,S;
    bool operator <($ _)const{return S==_.S?t2>_.t2:S>_.S;}
    void read(){scanf("%d%d%d",&t1,&t2,&S),++t1,++t2;}
}A[maxn];
std::vector<$>V[maxn];
std::priority_queue<$>Q;
int n,B,E,dp[maxn],ans=inf;
void in_put()
{
    scanf("%d%d%d",&n,&B,&E);++B,++E;
    for(int i=1;i<=n;++i)
    	A[i].read(),
    	V[A[i].t1].push_back(A[i]);
    //std::sort(A+1,A+n+1);
    memset(dp,inf,sizeof dp);dp[B-1]=0;
}
void solve_90()
{
    for(int i=1;i<=n;++i)
        if(A[i].t1<=B)dp[i]=A[i].S;
        else break;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<i;++j)
            if(A[j].t2>=A[i].t1-1)
                dp[i]=std::min(dp[j]+A[i].S,dp[i]);
        if(A[i].t2>=E)ans=std::min(dp[i],ans);
    }
    if(ans==inf)puts("-1");
    else printf("%d\n",ans);
}
void solve_100()
{
	for(int i=B;i<=E;++i)
	{
		if(dp[i-1]!=inf)
			for(int j=0;j<V[i].size();++j){$ now=V[i][j];now.S+=dp[i-1],Q.push(now);}
		while(!Q.empty())if(Q.top().t2<i)Q.pop();else break;
		if(!Q.empty())dp[i]=Q.top().S;
	}
	printf("%d\n",dp[E]!=inf?dp[E]:-1);
}
int main()
{
    in_put();
    solve_100();
}