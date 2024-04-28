#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=2e5+5,K=55;
int n,k,p,Cst[N],Clr[N],Sum[K][N];
long long ans;
int main()
{
	FILE("hotel");
	cin>>n>>k>>p;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&Clr[i],&Cst[i]),++Clr[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k;++j)Sum[j][i]=Sum[j][i-1];
		++Sum[Clr[i]][i];
	}
	for(int i=1,pos=0;i<=n;++i)
	{
		if(Cst[i]<=p)pos=i;
		ans+=Sum[Clr[i]][pos==i?pos-1:pos];
	}
	printf("%lld\n",ans);
	FCLS();
}