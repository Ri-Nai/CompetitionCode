#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
struct node{int x,y;}Q[N],t;
vector<node>P[N];
int n,m,dp[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&u,&v,&w),
		P[w].push_back((node){u,v});
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<P[i].size();++j)
		{
			int p=P[i][j].y,l=P[i][j].x,head=1,tail=0;
			for(int k=max(1,i-l+1);k<=i;++k)
			{
				t=(node){i-k+1,dp[k-1]+p*(i-k)};
				while(head<=tail&&Q[tail].y<=t.y)--tail;
				Q[++tail]=t;
			}
			for(int k=i;k<=min(n,i+l-1);++k)
			{
				dp[k]=max(dp[k],Q[head].y+p*(k-i+1));
				while(head<=tail&&Q[head].x+k-i>=l)++head;
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%d\n",dp[n]);
}