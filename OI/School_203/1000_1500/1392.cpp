#include<cmath>
#include<cstdio>
#include<cstring>
const int maxp=10005;
int a0,a1,b0,b1,n;
int pr[maxp],p[1000005],mp[maxp],A0[maxp],A1[maxp],B0[maxp],B1[maxp],tot,tmp,ans;
int gcd(const int &a,const int &b){return b?gcd(b,a%b):a;}
int lcm(const int &a,const int &b){return a/gcd(a,b)*b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int max(const int &a,const int &b){return a<b?b:a;}
void init()
{
	int k=sqrt(2e9);
	for(int i=2;i<=k;++i)
	{
		if(!p[i])
		{
			p[i]=1;pr[++pr[0]]=i;
			for(int j=i*i;j<=k;j+=i)p[j]=1;
		}
	}
}
void solve_BL()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		int ans=0;
		for(int i=1;i*i<=b1;++i)
			if(b1%i==0)
			{
				if(gcd(i,a0)==a1&&lcm(i,b0)==b1)++ans;
				if(b1/i!=i)
				{
					int x=b1/i;
					if(gcd(x,a0)==a1&&lcm(x,b0)==b1)++ans;
				}
			}
		printf("%d\n",ans);
	}
}
void resolve(int *A,int tmp)
{
	for(int i=1;i<=tot;++i)
		while(tmp%mp[i]==0)
			tmp/=mp[i],++A[i];
}
int work(int a0,int a1,int b0,int b1)
{
	int res=0;
	for(int i=a1;i<=b1;++i)
		if(max(b0,i)==b1&&min(a0,i)==a1)++res;
	return res;
}
void solve()
{
	init();
	scanf("%d",&n);
	while(n--)
	{
		memset(A0,0,sizeof A0);
		memset(A1,0,sizeof A1);
		memset(B0,0,sizeof B0);
		memset(B1,0,sizeof B1);
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		tmp=b1,tot=0,ans=1;
		for(int i=1;pr[i]*pr[i]<=tmp;++i)
			if(tmp%pr[i]==0)
			{
				mp[++tot]=pr[i];
				while(tmp%pr[i]==0)tmp/=pr[i],++B1[tot];//lcm
			}
		if(tmp!=1)mp[++tot]=tmp,B1[tot]=1;
		resolve(A0,a0);
		resolve(A1,a1);//gcd
		resolve(B0,b0);
		for(int i=1;i<=tot;++i)
			ans*=work(A0[i],A1[i],B0[i],B1[i]);
		printf("%d\n",ans);
	}
}
int main()
{
	solve();
}