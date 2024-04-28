#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
#define LISAN(x) x=lower_bound(B+1,B+len+1,x)-B
struct Que
{
	int id,x1,x2,y,flag;
	bool operator <(const Que &_)const
	{
		return y<_.y;
	}
}Q[N<<1],P[N];
int n,q,ans[N],B[N<<2],C[N<<2],len,tot;
void Add(int x,int y)
{
	while(x<=len)C[x]+=y,x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x-=x&-x;
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&P[i].x1,&P[i].y),B[++len]=P[i].x1;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		B[++len]=x1+1;B[++len]=x1;
		B[++len]=x2-1;B[++len]=x2;

		Q[++tot]=(Que){i,x1,x2,y1-1,-1};
		Q[++tot]=(Que){i,x1,x2,y2,1};
		Q[++tot]=(Que){i,x1+1,x2-1,y1,1};
		Q[++tot]=(Que){i,x1+1,x2-1,y2-1,-1};
	}
	sort(B+1,B+len+1);len=unique(B+1,B+len+1)-B-1;
	sort(P+1,P+n+1);sort(Q+1,Q+tot+1);
	for(int i=1;i<=n;++i)LISAN(P[i].x1);
	for(int i=1;i<=tot;++i)LISAN(Q[i].x1),LISAN(Q[i].x2);
	for(int i=1,j=1;i<=tot;++i)
	{
		while(j<=n&&P[j].y<=Q[i].y)Add(P[j++].x1,1);
		ans[Q[i].id]+=(Sum(Q[i].x2)-Sum(Q[i].x1-1))*Q[i].flag;
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
}