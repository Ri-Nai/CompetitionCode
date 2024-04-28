#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int n,m,A[N],B[N],tot,bg,ed;
bool vis[N];long long K;
bitset<N>cz[N];
int main()
{
	freopen("to.txt","w",stdout);
	scanf("%lld%d%d",&K,&m,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]),B[++tot]=A[i];
	if(K==1)
	{
		for(int i=1;i<=n;++i)
			printf("%d ",B[i]);
		return 0;
	}
	for(int t=2;t<=1500;++t)
	{
		memset(vis,0,sizeof vis);
		for(int i=1;i<=tot;++i)
			for(int j=1;j<=n;++j)
				vis[B[i]*A[j]%m]=1;
		tot=0;
		for(int i=0;i<m;++i)
			if(vis[i])cz[t].set(i),B[++tot]=i;
		bool flag=0;
		printf("Case #%d tot=%d:\n",t,tot);
		for(int i=1;i<=tot;++i)
			printf("%d ",B[i]);
		for(int i=2;i<t;++i)
			if(cz[t]==cz[i])
				flag=1,bg=i,ed=t;
		// if(t==K)
		// {
		// 	for(int i=1;i<=tot;++i)
		// 		printf("%d ",B[i]);
		// 	return 0;
		// }
		puts("");
		if(flag)
		{
			puts("now break");
			break;
		}
	}
	// K=(K-bg)%(ed-bg)+bg;
	// for(int i=0;i<m;++i)
	// 	if(cz[K].test(i))printf("%d ",i);
}
