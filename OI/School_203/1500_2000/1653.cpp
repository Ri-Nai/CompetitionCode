#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=3003;
typedef long long LL;
const LL inf=-1e18;
#define FOR(i,a,b) for(register int i=a,i##_=b;i<=i##_;++i)
bool vis[N];
int n,m,S,R[M],len[M],id[M][M];
int rd()
{
	int t=0,c,f=0; while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
struct SLP
{
	LL x,y;
	void read(int t) {x=rd(); y=rd(); y-=x*t;}
	LL Get(int T) {return x*T+y;}
	bool operator < (const SLP &_)const
	{
		return x<_.x;
	}
} Q[M][M],tmp[M][M],C[M],A[N];
inline void ToMax(LL &x,LL y) {x<y &&(x=y);}
inline bool chk(SLP a,SLP b,SLP c)
{
	return (b.y-a.y)*(b.x-c.x)<=(c.y-b.y)*(a.x-b.x);
}
void Updaaa(int p)
{
	int bp=p/S;
	if(vis[p])
	{
		int cnt=0;
		FOR(i,1,len[bp])
			if(id[bp][i]!=p)
			{
				id[bp][++cnt]=id[bp][i];
				tmp[bp][cnt]=tmp[bp][i];
			} 
		len[bp]=cnt;
	}
	vis[p]=1; R[bp]=0;
	bool flag=0;
	FOR(i,1,len[bp])
		if(tmp[bp][i]<A[p])
		{
			for(int j=++len[bp];j!=i;--j)
				tmp[bp][j]=tmp[bp][j-1],id[bp][j]=id[bp][j-1];
			tmp[bp][i]=A[p],id[bp][i]=p,flag=1;
			break;
		}
	if(!flag)tmp[bp][++len[bp]]=A[p],id[bp][len[bp]]=p;
	FOR(i,1,len[bp])
	{
		while(R[bp]>1&&chk(Q[bp][R[bp]-1],Q[bp][R[bp]],tmp[bp][i]))--R[bp];
		Q[bp][++R[bp]]=tmp[bp][i];
	}	
}
void Qrrry(int T,int lp,int rp)
{
	if(lp>rp)swap(lp,rp);
	int l=lp/S,r=rp/S;
	LL res=inf;
	if(l^r)
	{
		FOR(i,lp,(l+1)*S-1)if(vis[i])ToMax(res,A[i].Get(T));
		FOR(i,r*S,rp)if(vis[i])ToMax(res,A[i].Get(T));
		FOR(i,l+1,r-1)
		{
			if(!R[i])continue;
			while(R[i]>1&&Q[i][R[i]].Get(T)<Q[i][R[i]-1].Get(T))--R[i];
			ToMax(res,Q[i][R[i]].Get(T));
		}
	}
	else FOR(i,lp,rp)if(vis[i])ToMax(res,A[i].Get(T));
	if(res==inf)puts("nema");
	else printf("%lld\n",res);
}
int main()
{
	n=rd(); S=sqrt(n)+1; m=rd();
	for(int i=1,op,t,k; i<=m; ++i)
	{
		if(rd()==1)t=rd(),A[k=rd()].read(t),Updaaa(k);
		else t=rd(),k=rd(),Qrrry(t,k,rd());
	}
}
