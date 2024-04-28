#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=1e4+7;
int n,C,m,A[maxn],B[maxn],sum[maxn<<2][22],tot[maxn<<2];
int read()
{
    int t=0,c;
    do c=getchar();while(c<48||c>57);
    while(c>=48&&c<=57)t=(t<<1)+(t<<3)+(c^48),c=getchar();
    return t;
}
void Up(int p)
{
	const int &ls=p<<1,&rs=p<<1|1;
	for(int i=0;i<C;++i)
	{
		sum[p][i]=0;
		for(int j=0;j<=i;++j)
			sum[p][i]=(sum[p][i]+sum[ls][j]*sum[rs][i-j]%mod)%mod;
	}
	tot[p]=tot[ls]*tot[rs]%mod;
}
void updata(int x,int L=1,int R=n,int p=1)
{
	if(L==R)
	{
		sum[p][0]=B[L]%mod;sum[p][1]=A[L]%mod;
		tot[p]=(A[L]+B[L])%mod;;
		return;
	}
	const int &ls=p<<1,&rs=p<<1|1,mid=L+R>>1;
	if(!x)updata(0,L,mid,ls),updata(0,mid+1,R,rs);
	else if(x<=mid)updata(x,L,mid,ls);
	else updata(x,mid+1,R,rs);Up(p);
}
int query()
{
	int res=0;
	for(int i=0;i<C;++i)res=(res+sum[1][i])%mod;
	return (tot[1]-res+mod)%mod;
}
int main()
{
	n=read();C=read();
	for(int i=1;i<=n;++i)A[i]=read();
	for(int i=1;i<=n;++i)B[i]=read();
	updata(0);
	for(m=read();m--;)
	{
		int x=read();
		A[x]=read();
		B[x]=read();
		updata(x);
		printf("%d\n",query());
	}
}