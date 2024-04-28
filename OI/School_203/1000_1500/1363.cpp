#include<cstdio>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	int x,y,ans=0;
	scanf("%d%d",&x,&y);
	if(y%x==0)
	{

		int t=y/x;
		for(int i=1;i*i<=t;++i)
		{
			if(t%i==0)
			{
				int j=t/i;
				if(gcd(i,j)==1)
					{}ans+=2;
				if(i==j)--ans;
			}
		}
	}
	printf("%d\n",ans);
}