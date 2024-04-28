#include<cstdio>
const int maxn=1e5+5;
int n,m,A[maxn];
char tmp[10];
long long C1[maxn],C2[maxn];
void update(int x,int y)
{
	for(int i=x;i<=n;i+=i&-i)
		C1[i]+=y,C2[i]+=1ll*y*(x-1);
}
long long query(int x)
{
	long long res=0;
	for(int i=x;i>0;i-=i&-i)
		res+=1ll*x*C1[i]-C2[i];
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
		scanf("%s%d",tmp,&x);
		if(tmp[0]=='M')scanf("%d",&y),update(x,y-A[x]),A[x]=y;
		else printf("%lld\n",query(x));
	}
}