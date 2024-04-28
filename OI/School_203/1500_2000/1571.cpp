#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,i##_=b;i<=i##_;++i)
#define DOR(i,a,b) for(int i=a,i##_=b;i>=i##_;--i)
const int N=3e5+5;
int stk[N],top,mn[2][N],mx[2][N],A[N],n;
void work1(int i,int id,int p)
{
	if(p==-1)while(top&&A[stk[top]]>A[i])
			mn[id][stk[top]]=i+p,--top;
	else while(top&&A[stk[top]]>=A[i])
			mn[id][stk[top]]=i+p,--top;
	stk[++top]=i;
}
void work2(int i,int id,int p)
{
	if(p==-1)while(top&&A[stk[top]]<A[i])
			mx[id][stk[top]]=i+p,--top;
	else while(top&&A[stk[top]]<=A[i])
			mx[id][stk[top]]=i+p,--top;
	stk[++top]=i;
}
int main()
{
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&A[i]);
	FOR(i,1,n)work1(i,0,-1);
	while(top)mn[0][stk[top]]=n,--top;
	DOR(i,n,1)work1(i,1,1);
	while(top)mn[1][stk[top]]=1,--top;
	FOR(i,1,n)work2(i,0,-1);
	while(top)mx[0][stk[top]]=n,--top;
	DOR(i,n,1)work2(i,1,1);
	while(top)mx[1][stk[top]]=1,--top;
	long long ans=0;
	FOR(i,1,n)
	{
		//printf("%d %d %d %d\n",mn[0][i],mn[1][i],mx[0][i],mx[1][i]);
		ans+=1ll*A[i]*(mx[0][i]-i+1)*(i-mx[1][i]+1);
		ans-=1ll*A[i]*(mn[0][i]-i+1)*(i-mn[1][i]+1);
	}
	printf("%lld\n",ans);
}