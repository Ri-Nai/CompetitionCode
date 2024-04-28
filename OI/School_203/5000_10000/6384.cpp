#include<bits/stdc++.h>
using namespace std;
typedef unsigned uint;
#define ls p<<1
#define rs p<<1|1
bool Nai;
const int N=1e6+5;
const uint P=19260817;
uint Hash,now,pw[N],h[N<<2];
int n,m,A[N],num[N<<2],pos[N],ans[N],tot;
struct Climb
{
	int x,id;
	bool operator <(const Climb &_)const
	{
		return x<_.x;
	}
}B[N];
void build(int L=1,int R=m,int p=1)
{
	if(L==R)return (void)(pos[L]=p);
	int mid=L+R>>1;
	build(L,mid,ls);build(mid+1,R,rs);
}
void Updata(int p,int y)
{
	num[p]=!!y;h[p]=y;
	for(p>>=1;p;p>>=1)
	{
		num[p]=num[ls]+num[rs],
    	h[p]=h[ls]*pw[num[rs]]+h[rs];
	}
}
bool Ri;
int main()
{
	//printf("%f\n",(&Ri-&Nai)/1024.0/1024);
	scanf("%d%d",&n,&m);pw[0]=1;build();
	for(int i=1,x;i<=n;++i)
		pw[i]=pw[i-1]*P,Hash+=pw[i-1],
		scanf("%d",&x),now=now*P+x;
	for(int i=1;i<=m;++i)
		scanf("%d",&A[i]),B[i]=(Climb){A[i],i};
	sort(B+1,B+m+1);
	for(int i=1;i<=m;++i)A[B[i].id]=i;
	for(int i=1;i<=m;++i)
	{
		Updata(pos[A[i]],i);
		if(i>=n)
		{
			if(now==h[1])ans[++tot]=i-n+1;
			Updata(pos[A[i-n+1]],0);now+=Hash;
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)
		printf("%d ",ans[i]);
	return Ri-Nai;
}