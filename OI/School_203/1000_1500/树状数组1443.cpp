#include<cstdio>
const int maxn=1e5+5;
int n,m;
char tmp[10];
int A[maxn],C[maxn];
inline int lowbit(const int &x){return x&(~x+1);}
void update(int x,int y)
{
	while(x<=n)
	{
		C[x]+=y;
		x+=lowbit(x);
	}
}
long long query(int x)
{
	long long res=0;
	while(x>0)
	{
		res+=C[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),
		update(i,A[i]);
	while(m--)
	{
		int x,y;
		scanf("%s%d%d",tmp,&x,&y);
		if(tmp[0]=='C')update(x,y-A[x]),A[x]=y;
		else printf("%lld\n",query(y)-query(x-1));
	}
}