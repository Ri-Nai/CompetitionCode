#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=2e4+5;
int n,k,D[maxn],C[maxn],S[maxn],to[maxn],tot,
	W[maxn],L[maxn],R[maxn],nxt[maxn],head[maxn];
LL ans,dp[maxn];
void Add(int u,int v)
{
	to[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int read()
{
	int t=0,c;
	do c=getchar();while(c<48||c>57);
	while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return t;
}
struct Seg
{
#define ls p<<1
#define rs p<<1|1
#define mid (L+R>>1)
	LL mn[maxn<<2],lazy[maxn<<2];
	void Change(int p,LL Add)
	{
		mn[p]+=Add;lazy[p]+=Add;
	}
	void Up(int p)
	{
		mn[p]=min(mn[ls],mn[rs]);
	}
	void Down(int p)
	{
		if(!lazy[p])return;
		Change(ls,lazy[p]);
		Change(rs,lazy[p]);
		lazy[p]=0;
	}
	void build(int L,int R,int p)
	{
		lazy[p]=0;
		if(L==R){mn[p]=dp[L];return;}
		build(L,mid,ls);
		build(mid+1,R,rs);
		Up(p);
	}
	void updata(int L,int R,int l,int r,LL x,int p)
	{
		if(l==L&&R==r){Change(p,x);return;}
		Down(p);
		if(r<=mid)updata(L,mid,l,r,x,ls);
		else if(l>mid)updata(mid+1,R,l,r,x,rs);
		else updata(L,mid,l,mid,x,ls),updata(mid+1,R,mid+1,r,x,rs);
		Up(p);
	}
	LL query(int L,int R,int l,int r,int p)
	{
		if(l==L&&R==r){return mn[p];}
		Down(p);
		if(r<=mid)return query(L,mid,l,r,ls);
		else if(l>mid)return query(mid+1,R,l,r,rs);
		else return min(query(L,mid,l,mid,ls),query(mid+1,R,mid+1,r,rs));
	}
}T;
int main()
{
	n=read();k=read()+1;
	for(int i=2;i<=n;++i)D[i]=read();
	for(int i=1;i<=n;++i)C[i]=read();
	for(int i=1;i<=n;++i)S[i]=read();
	for(int i=1;i<=n;++i)W[i]=read();
	D[++n]=2e9;
	for(int i=1;i<=n;++i)
	{
		L[i]=lower_bound(D+1,D+n+1,D[i]-S[i])-D;
		R[i]=upper_bound(D+1,D+n+1,D[i]+S[i])-D-1;
		Add(R[i],i);
	}
	for(int i=1;i<=k;++i)
	{
		if(i==1)
		{
			LL res=0;
			for(int j=1;j<=n;++j)
			{
				dp[j]=res+C[j];
				for(int k=head[j];k;k=nxt[k])
					res+=W[to[k]];
			}
			ans=dp[n];
		}
		else
		{
			T.build(1,n,1);
			for(int j=1;j<=n;++j)
			{
				if(j<i)dp[j]=C[j];
				else dp[j]=T.query(1,n,i-1,j-1,1)+C[j];
				for(int k=head[j];k;k=nxt[k])
				{
					const int &now=to[k];
					if(L[now]>=2)T.updata(1,n,1,L[now]-1,W[now],1);
				}
			}
			ans=min(ans,dp[n]);
		}
	}
	printf("%lld\n",ans);
}