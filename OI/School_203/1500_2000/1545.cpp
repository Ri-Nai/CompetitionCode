#include<bits/stdc++.h>
#define Mn(a,b) (a>b&&(a=b));
typedef long long LL;
using namespace std;
int n,to[1005];LL T;
struct Mat
{
	LL A[105][105],mn;
	Mat(){memset(A,0x3f,sizeof A);mn=A[0][0];}
	Mat operator *(const Mat &M)const
	{
		Mat res;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=n;++k)
					Mn(res.A[i][j],A[i][k]+M.A[k][j]);
				Mn(res.mn,res.A[i][j]);
			}
		return res;
	}
}f[51],ans;
int main()
{
	scanf("%d%lld",&n,&T);
	for(int i=1,k,W;i<=n;++i)
	{
		scanf("%d%d",&k,&W);
		for(int j=1;j<=k;++j)scanf("%d",&to[j]);
		for(int j=1,w;j<=k;++j)
		{
			scanf("%d",&w);
			Mn(f[0].A[i][to[j]],W+w);
			Mn(f[0].mn,W+w);
		}
	}
	ans=f[0];LL tot=1;
	for(int i=1;i<=50;++i)f[i]=f[i-1]*f[i-1];
	for(int i=50;i>=0;--i)
	{
		Mat tmp=ans*f[i];
		if(tmp.mn<=T)ans=tmp,tot+=1ll<<i;
	}
	printf("%lld\n",tot);
}