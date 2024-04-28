#include<cstdio>
const int maxn=1005;
int C[maxn],A[maxn],ans,n;
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int lowbit(const int &x){return x&-x;}
void ToMax(int x,int a)
{
	while(x<maxn)
		C[x]=max(C[x],a),
		x+=lowbit(x);
}
int GetMax(int x)
{
	int res=0;
	while(x>0)
		res=max(C[x],res),
		x-=lowbit(x);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),++A[i];
	for(int i=1;i<=n;++i)
	{
		int res=GetMax(A[i]-1)+1;
		if(res>C[A[i]])ToMax(A[i],res);
		ans=max(ans,res);
	}
	printf("%d\n",ans);
}