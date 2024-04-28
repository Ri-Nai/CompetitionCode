#include<cstdio>
#define ls p<<1
#define rs p<<1|1
const int maxn=5e4+5;
int n,m,ans[maxn],tot,C[maxn],A[maxn];
void Add(int x,int y){while(x<=n)C[x]+=y,x+=x&-x;}
int sum(int x,int res=0){while(x)res+=C[x],x-=x&-x;return res;}
int Find(int id)
{
	if(A[id]==0)return 0;
	int l=1,r=id-1,L=id,R=id;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(sum(id-1)-sum(mid-1)==id-mid)
			L=mid,r=mid-1;
		else l=mid+1;
	}
	l=id+1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(sum(mid)-sum(id)==mid-id)
			R=mid,l=mid+1;
		else r=mid-1;
	}
	return R-L+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)Add(i,A[i]=1);
	for(int i=1;i<=m;++i)
	{
		char tmp[2];int id;
		scanf("%s",tmp);
		if(tmp[0]!='R')scanf("%d",&id);
		if(tmp[0]=='D')Add(ans[++tot]=id,-1),A[id]=0;
		if(tmp[0]=='R')Add(id=ans[tot--],+1),A[id]=1;
		if(tmp[0]=='Q')printf("%d\n",Find(id));
	}
}