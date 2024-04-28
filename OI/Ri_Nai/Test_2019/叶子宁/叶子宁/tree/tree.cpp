#include<cstdio>
const int maxn=1e6+5;
int n,num[maxn],a[maxn],r[maxn],l[maxn];
void pre()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&l[i],&r[i]);
}
void dfs(int t)
{
	num[t]=1;
	if(~l[t])dfs(l[t]),num[t]+=num[l[t]];
	if(~r[t])dfs(r[t]),num[t]+=num[r[t]];
}
bool pd(int x,int y)
{
	if(x==-1&&y==-1)return 1;
	if(x==-1||y==-1)return 0;
	if(a[x]==a[y])
		return pd(l[x],r[y])&&pd(l[y],r[x]);
	return 0;
}
void solve()
{
	pre();
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;++i)
		if(pd(l[i],r[i])&&num[i]>ans)
			ans=num[i];
	printf("%d\n",ans);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	solve();
}
/*
2
1 3
2 -1
-1 -1
*/
