#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55,M=1e5;
double B[N];
int n,m,tot;
bool mark[N];
LL A[N],L,R,ans[N];
int main()
{
	scanf("%d%lld%lld",&m,&L,&R);
	L*=M,R*=M;
	for(int i=1;i<=m;++i)
		scanf("%lf",&B[i]),A[i]=round(B[i]*M);
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			LL now=A[j],df=A[j]-A[i];
			if(now%df)continue;
			bool flag=1,pd=mark[j];
			for(int k=j+1;k<=m&&flag;++k)
				if(A[k]==now+df)now=A[k],pd&=mark[k];
				else if(A[k]>now+df)flag=0;
			if(flag==0||pd||now+df<=R)continue;
			mark[j]=mark[i]=1;now=A[j];
			for(int k=j+1;k<=m;++k)
				if(A[k]==now+df)now=A[k],mark[k]=1;
			ans[++tot]=df;
			break;
		}
	}
	for(int i=1;i<=m;++i)if(!mark[i])ans[++tot]=A[i];
	for(int i=1;i<=tot;++i)printf("%.5f\n",ans[i]*1.0/M);
}
/*
9
9 25
9 10 12 15 18 20 21 24 25

3 5

3 10 25
*/