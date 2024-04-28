#include<bits/stdc++.h>
using namespace std;
int n,k,m,p,cnt[1<<25],ans;
void dfs1(int x,int y)
{
	if(!x)++cnt[y];
	else for(int i=1;i<=26;++i)dfs1(x-1,(y*33^i)&m);
}
void dfs2(int x,int y)
{
	if(!x)ans+=cnt[y];
	else for(int i=1;i<=26;++i)dfs2(x-1,((y^i)*p)&m);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	m=(1<<m)-1;
	for(int i=1;i<=m;++i)
		if((i*33&m)==1&&(p=i))//求出%m下33的逆元
			break;
	dfs1(n>>1,0);dfs2(n+1>>1,k);
	printf("%d\n",ans);
}