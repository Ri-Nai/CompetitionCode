#include<cstdio>
#include<algorithm>
const int maxn=1e5+5;
struct $
{
	int x,y,val;
	void read(){scanf("%d%d%d",&x,&y,&val);}
	bool operator <($ _)const{return y==_.y?x<_.x:y<_.y;}
}P[maxn];
int n,m,k,x0[maxn],y0[maxn],C[maxn];
void update(int x,int y){while(x<maxn)C[x]=std::max(C[x],y),x+=x&-x;}
int Get(int x){int res=0;while(x)res=std::max(res,C[x]),x-=x&-x;return res;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)P[i].read(),x0[i]=P[i].x,y0[i]=P[i].y;
	std::sort(x0+1,x0+k+1);n=std::unique(x0+1,x0+k+1)-x0-1;
	std::sort(y0+1,y0+k+1);m=std::unique(y0+1,y0+k+1)-y0-1;
	for(int i=1;i<=k;++i)
		P[i].x=std::lower_bound(x0+1,x0+n+1,P[i].x)-x0,
		P[i].y=std::lower_bound(y0+1,y0+m+1,P[i].y)-y0;
	std::sort(P+1,P+k+1);
	for(int i=1;i<=k;++i)
	{
		int x=P[i].x,y=P[i].y,val=P[i].val;
		int tmp=Get(x)+val;update(x,tmp);
	}
	printf("%d\n",Get(n));
}