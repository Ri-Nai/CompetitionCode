#include<cstdio>
#include<algorithm>
int rc,rh,bc,bh;
int gcd(int a,int b){b?gcd(b,a%b):a;}
int main()
{
	scanf("%d%d%d%d",&rc,&rh,&bc,&bh);
	if(rh==bh)
	{
		if(rc==bc)printf("%d\n",2*rc);
		else printf("%d\n",2*std::min(rc,bc)+1);
	}
	else
	{
		if(rc==bc)printf("%d\n",3*rc);
		else printf("%d\n",3*std::min(rc,bc)+1);
	}
}