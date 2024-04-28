#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=1e4+5,MQ=2e5;
typedef long long LL;
int n,m,q;
LL ans[M],C[N];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
LL Sum(int x)
{
	LL res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
struct Que
{
	int id,x,y,v;
	bool operator < (const Que &_)const
	{
		if(x!=_.x)return x<_.x;
        if(y<_.y)return y<_.y;
        return !id;
	}
}Q[MQ],B[MQ];
void Solve(int L,int R)
{
	if(L==R)return ;
	int mid=L+R>>1,tot=0;
	for(int i=L;i<=mid;++i)if(!Q[i].id)B[++tot]=Q[i];
	for(int i=mid+1;i<=R;++i)if(Q[i].id)B[++tot]=Q[i];
	sort(B+1,B+tot+1);
	for(int i=1;i<=tot;++i)
	{
		int id=B[i].id,y=B[i].y,v=B[i].v;
		if(id)ans[id]+=Sum(y)*v;
		else Add(y,v);
	}
	for(int i=1;i<=tot;++i)if(!B[i].id)Add(B[i].y,-B[i].v);
	Solve(L,mid);Solve(mid+1,R);
}
int main()
{
	rd();n=rd();
	for(int op,x1,y1,x2,y2,v;(op=rd())!=3;)
		if(op==1)
			x1=rd(),y1=rd(),v=rd(),Q[++m]=(Que){0,x1,y1,v};
		else
		{
			x1=rd(),y1=rd(),x2=rd(),y2=rd();++q;
			Q[++m]=(Que){q,x1-1,y2,-1};
			Q[++m]=(Que){q,x1-1,y1-1,1};
			Q[++m]=(Que){q,x2,y2,1};
			Q[++m]=(Que){q,x2,y1-1,-1};
	}
	Solve(1,m);
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
}