#include<cmath>
#include<cstdio>
const int maxn=1e6+5,maxp=1e5+5;
int n,A[105],cnt[105][maxp],
sum[maxp],id[maxn],num,Gcd=1;
int pr[maxp],p[maxn],tot;
void init()
{
	p[0]=p[1]=1;int M=1e6;
	for(int i=2;i<=M;++i)
	{
		if(!p[i])
		{
			pr[++tot]=i;p[i]=tot;
			for(int j=i+i;j<=M;j+=i)p[j]=1;
		}
	}
	//printf("%d\n",tot);
}
void resolve(int id,int T)
{
	for(int i=1;i<=tot;++i)
	{
		if(T%pr[i]==0)
			while(T%pr[i]==0)
				T/=pr[i],++cnt[id][i],++sum[i];
		//if(p[T])++cnt[id][p[T]],++sum[p[T]],T=1;
		if(T==1)return ;
	}
}
int main()
{
	init();scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),
		resolve(i,A[i]);
	for(int i=1;i<=tot;++i)
	{
		sum[i]/=n;
		if(sum[i])
			Gcd*=pow(pr[i],sum[i]);
	}
	printf("%d ",Gcd);int ans=0;
	for(int i=1;i<=tot;++i)
	{
		if(sum[i])
		{
			int small=0,large=0;
			for(int j=1;j<=n;++j)
			{
				int tmp=sum[i]-cnt[j][i];
				if(tmp<0)large+=-tmp;
				else small+=tmp;
			}
			//if(tmp>0)ans+=tmp;
			if(large>small)ans+=small;
			else ans+=large;

		}
	}
	printf("%d\n",ans);
}
