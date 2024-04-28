#include<cstdio>
int n,A[20];
int kangtuo()
{
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=0;int c=1,m=1;
		for(int j=i+1;j<=n;++j)
		{
			if(A[j]<A[i])++x;
			m*=c;c++;
		}
		ans+=x*m;
	}
	return ans;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	printf("%d",kangtuo()+1);
}