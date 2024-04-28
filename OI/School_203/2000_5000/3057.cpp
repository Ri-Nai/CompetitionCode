#include<bits/stdc++.h>
using namespace std;
#define mid (L+R>>1)
#define Lson L,mid,p<<1
#define Rson mid+1,R,p<<1|1
#define LR int L=1,int R=len,int p=1
#define LW(x) lower_bound(B+1,B+len+1,x)-B
const int N=1e5+5;
int n,S,W,B[N],len,L[N],mx[N<<2],lz[N<<2];
struct Point
{
	int x,y;
	void read()
	{
		scanf("%d%d",&x,&y);B[++len]=x;
	}
	bool operator <(const Point &_)const
	{
		return y<_.y;
	}
}A[N];
inline void change(int p,int x)
{
	mx[p]+=x;lz[p]+=x;
}
inline void Down(int p)
{
	if(!lz[p])return;
	change(p<<1,lz[p]);
	change(p<<1|1,lz[p]);
	lz[p]=0;
}
void Updata(int l,int r,int x,LR)
{
	if(l==L&&R==r)return change(p,x);Down(p);
	if(r<=mid)Updata(l,r,x,Lson);
	else if(l>mid)Updata(l,r,x,Rson);
	else Updata(l,mid,x,Lson),Updata(mid+1,r,x,Rson);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
int main()
{
	scanf("%d%d%d",&n,&S,&W);
	for(int i=1;i<=n;++i)A[i].read();
	sort(B+1,B+n+1);sort(A+1,A+n+1);
	len=unique(B+1,B+1+len)-1-B;
	for(int i=1;i<=len;++i)L[i]=LW(B[i]-S);
	for(int i=1;i<=n;++i)A[i].x=LW(A[i].x);
	int now=1,ans=0;
	for(int i=1;i<=n;++i)
	{
		while(now<=n&&A[now].y<A[i].y-W)
			Updata(L[A[now].x],A[now].x,-1),++now;
		Updata(L[A[i].x],A[i].x,1);
		ans=max(ans,mx[1]);
	}
	printf("%d\n",ans);
}