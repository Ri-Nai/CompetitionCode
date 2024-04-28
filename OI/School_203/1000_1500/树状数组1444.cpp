#include<cstdio>
const int maxn=1e5+5;
int n,m;
char tmp[10];
int A[maxn];
long long C1[maxn],C2[maxn];
inline int lowbit(const int &x){return x&(~x+1);}
void update(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		C1[i]+=y,C2[i]+=y*(x-1);
}
long long query(int x)
{
	long long res=0;
	for(int i=x;i>0;i-=lowbit(i))
		res+=x*C1[i]-C2[i];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),
		update(i,A[i]-A[i-1]);
	while(m--)
	{
		int x,y,v;
		scanf("%s%d%d",tmp,&x,&y);
		if(tmp[0]=='A')scanf("%d",&v),update(x,v),update(y+1,-v);
		else printf("%lld\n",query(y)-query(x-1));
	}
}