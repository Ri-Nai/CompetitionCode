#include<cstdio>
const int maxn=5e4+5;
int n,stk[maxn],val[maxn],top,L[maxn],R[maxn];
long long mx,tmp;
int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&val[i]);
	for(int i=1;i<=n;++i)
	{
		while(top&&val[stk[top]]>val[i])
			R[stk[top]]=i-stk[top]-1,--top;
		stk[++top]=i;
	}
	while(top)R[stk[top]]=n-stk[top],--top;
	for(int i=n;i>=1;--i)
	{
		while(top&&val[stk[top]]>val[i])
			L[stk[top]]=stk[top]-i-1,--top;
		stk[++top]=i;
	}
	while(top)L[stk[top]]=stk[top]-1,--top;
	for(int i=1;i<=n;++i)
	{
		//printf("%d %d\n",L[i],R[i]);
		tmp=1ll*(L[i]+R[i]+1)*val[i];
		if(tmp>mx)mx=tmp;
	}
	printf("%lld\n",mx);
}
