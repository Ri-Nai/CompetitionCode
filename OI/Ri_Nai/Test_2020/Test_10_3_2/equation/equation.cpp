#include<bits/stdc++.h>
using namespace std;
const int N=105,P=5,M=1e6+5;
const int p[]={1033,2267,3559,4877,271};
int n,m,A[N][P],flag[N],res[2][P][5005],ans[M],tot;
char s[N*N];
void init(int id,char *s,int len)
{
	for(int i=0;i<len;++i)
		for(int j=0;j<P;++j)
			A[id][j]=((A[id][j]<<1)+(A[id][j]<<3)+(s[i]^48))%p[j];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i)
	{
		scanf("%s",&s);
		flag[i]=*s=='-';
		init(i,s+flag[i],strlen(s)-flag[i]);
	}
	for(int i=0;i<P;++i)
		for(int j=1;j<=p[i];++j)
		{
			int now=1;
			for(int k=0;k<=n;++k)
			{
				bool f=flag[k];
				res[f][i][j]=(now*A[k][i]+res[f][i][j])%p[i],now=now*j%p[i];
			}
		}
	for(int i=1;i<=m;++i)
	{
		bool flag=1;
		for(int k=0;flag&&k<P;++k)
			if(res[0][k][i%p[k]]!=res[1][k][i%p[k]])flag=0;
		if(flag)ans[++tot]=i;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)printf("%d\n",ans[i]);
}