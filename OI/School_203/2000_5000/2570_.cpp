#include<cmath>
#include<cstdio>
#include<cstring>
const int maxn=1e5+5,maxm=maxn*100;
int n,m,A[maxn],id[maxn];
long long ans;
int read()
{
    int t=0,c;
    do c=getchar();while(c<48||c>57);
    while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
struct SEG
{
	int Lson[maxm],Rson[maxm],val[maxm],tot;
	SEG(){tot=0;}
	void Update(int L,int R,int x,int y,int &rt)
	{
		if(!rt)rt=++tot;
		val[rt]+=y;
		if(L==R)return ;
		int mid=L+R>>1;
		if(x<=mid)Update(L,mid,x,y,Lson[rt]);
		else Update(mid+1,R,x,y,Rson[rt]);
	}
	int query(int L,int R,int l,int r,int rt)
	{
		if(!rt)return 0;
		if(l==L&&R==r)return val[rt];
		int mid=L+R>>1;
		if(r<=mid)return query(L,mid,l,r,Lson[rt]);
		if(l>mid)return query(mid+1,R,l,r,Rson[rt]);
		return query(L,mid,l,mid,Lson[rt])+query(mid+1,R,mid+1,r,Rson[rt]);
	}
};
struct BIT
{
	SEG Seg;
	int C[maxn];
	BIT(){}
	void Add(int x,int y,int z)
	{
		while(x<=n)Seg.Update(1,n,y,z,C[x]),x+=x&-x;
	}
	int sum(int x,int l,int r)
	{
		int res=0;
		while(x)res+=Seg.query(1,n,l,r,C[x]),x-=x&-x;
		return res;
	}
}Bit;
void Renew(int x,int id)
{
	Bit.Add(id,x,-1);
	ans-=Bit.sum(id-1,x+1,n);
	ans-=Bit.sum(n,1,x-1)-Bit.sum(id,1,x-1);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)id[A[i]=read()]=i;
	for(int i=1;i<=n;++i)Bit.Add(i,A[i],1),ans+=Bit.sum(i-1,A[i]+1,n);
	for(int i=1,x;i<=m;++i)
	{
		printf("%lld\n",ans);
		x=read();
		Renew(x,id[x]);
	}
}