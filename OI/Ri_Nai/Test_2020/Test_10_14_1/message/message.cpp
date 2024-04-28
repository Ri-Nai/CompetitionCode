#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=2e5+5;
int n,fa[N],in[N],stk[N],top,ans=N;
void solve(int u)
{
	int cnt=0,v=u;
	do in[v]=0,++cnt,v=fa[v];while(v!=u);
	ans=min(ans,cnt);
}
int main()
{
	FILE("message");
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&fa[i]),++in[fa[i]];
	for(int i=1;i<=n;++i)if(!in[i])stk[++top]=i;
	while(top)
	{
		int u=stk[top--];
		if(!--in[fa[u]])stk[++top]=fa[u];
	}
	for(int i=1;i<=n;++i)if(in[i])solve(i);
	printf("%d\n",ans);
	FCLS();
}
