#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define Re register
#define cc const int &
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
#define LR cc L=1,cc R=Q,cc p=1
#define ToMax(x,y) (x<(y))&&(x=y)
bool Nai;
const int N=1.5e4+5,P=N<<2,M=P*100,inf=-0x3f3f3f3f;
int Q,MXV,T,ans,dp[20][N];
int nxt[M],to[M],head[P],W[M],tot;
bool vis[P];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
inline void Add(cc u,cc v,cc w)
{
	nxt[++tot]=head[u];
	to[head[u]=tot]=v;
	W[tot]=w;
}
void Updata(cc l,cc r,cc v,cc w,LR)
{
	if(l==L&&R==r)return Add(p,v,w);
	cc mid=L+R>>1;
	if(r<=mid)Updata(l,r,v,w,Lson);
	else if(l>mid)Updata(l,r,v,w,Rson);
	else Updata(l,mid,v,w,Lson),Updata(mid+1,r,v,w,Rson);
}
void Query(cc x,cc y,cc dep=1,LR)
{
	if(!vis[p])
	{
		vis[p]=1;
		memcpy(dp[dep],dp[dep-1],sizeof dp[dep]);
		for(Re int i=head[p];i;i=nxt[i])
		{
			int v=to[i],w=W[i];
			for(Re int j=MXV;j>=v;--j)
				ToMax(dp[dep][j],dp[dep][j-v]+w);
		}
	}
	if(L==R)
	{
		if(dp[dep][y]>=0)
			printf("1 %d\n",ans=dp[dep][y]),ans^=1;
		else puts("0 0"),ans=0;
		return ;
	}
	cc mid=L+R>>1;
	if(x<=mid)Query(x,y,dep+1,Lson);
	else Query(x,y,dep+1,Rson);
}
bool Ri;
int main()
{
	Q=rd();MXV=rd();T=rd();
	memset(dp[0],inf,sizeof dp[0]);
	dp[0][0]=0;
	for(Re int i=1,op,v,w;i<=Q;++i)
	{
		int d=T*ans;op=rd();v=rd()-d;
		if(op==1)w=rd()-d,Updata(i,rd()-d,v,w);
		else Query(i,v);
	}
}