#include<cstdio>
#define Fasdas
inline int min(const int &a,const int &b)
{
	return a<b?a:b;
} 
inline int abs(const int &a)
{
	return a>0?a:-a;
}
int gcd(const int &a,const int &b)
{
	return b?gcd(b,a%b):a;
}
void solve()
{
	int a,b,x,y,p;
	scanf("%d%d%d%d",&a,&x,&b,&y);
	p=gcd(x,y);
	printf("%d\n",min(p-abs(a-b)%p,abs(a-b)%p));
}
signed main()
{
	#ifndef F
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
