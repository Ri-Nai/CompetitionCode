#include<cstdio>
#define LL long long
LL x,y,a,b; 
void exgcd(LL a,LL b)
{
	if(b==0){x=1;y=0;return;} 
	exgcd(b,a%b);
	LL tx=x;x=y;y=tx-a/b*y; 
}
int main()
{
	scanf("%d%d",&a,&b);
	exgcd(a,b);
	x=(x%b+b)%b;
	printf("%lld\n",x);
}
