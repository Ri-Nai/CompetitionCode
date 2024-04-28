#include<cstdio>
int n,S,A[35],len;
void change(int n,int p)
{
	len=0;
	while(n)
		A[++len]=n%p,n/=p;
}
bool judge()
{
	for(int i=1,j=len;i<=j;++i,--j)
		if(A[i]!=A[j])return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&S);
	for(int i=S+1;;++i)
	{
		int cnt=0;
		for(int j=2;j<=10;++j)
		{
			change(i,j);
			cnt+=judge();
			if(cnt>=2){printf("%d\n",i);--n;break;}
		}
		if(n==0)break;
	}
}