#include<bits/stdc++.h>
using namespace std;
int mp[6][8],tmp[6][6][8],n,ans[6][3];
bool mark[6][8],flag;
void chk()
{
	for(int i=1; i<=5; ++i)if(mp[i][1])return ;
	for(int i=1; i<=n; ++i)
		printf("%d %d %d\n",ans[i][0]-1,ans[i][1]-1,ans[i][2]);
	exit(0);
}
inline bool cmp(int a,int b,int c)
{
	return a&&a==b&&b==c;
}
inline void Doit(int i,int j,int p)
{
	if(i+p<=5&&i+p>=1&&cmp(mp[i][j],mp[i+p][j],mp[i+p+p][j]))
		flag=mark[i][j]=mark[i+p][j]=mark[i+p+p][j]=1;
	if(j+p<=7&&j+p>=1&&cmp(mp[i][j],mp[i][j+p],mp[i][j+p+p]))
		flag=mark[i][j]=mark[i][j+p]=mark[i][j+p+p]=1;
}
void Del()
{
	flag=0;
	for(int i=1; i<=5; ++i)
		for(int j=1,t,k=0; j<=7; ++j)
			if(mp[i][j])t=mp[i][j],mp[i][j]=0,mp[i][++k]=t;
	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
			Doit(i,j,1),Doit(i,j,-1);
	if(!flag)return ;
	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
			if(mark[i][j])mark[i][j]=mp[i][j]=0;
	Del();
}
void dfs(int stp)
{
	if(stp==n+1)return chk();
	memcpy(tmp[stp],mp,sizeof mp);
	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
		{
			if(!mp[i][j])continue;
			if(i!=5&&mp[i][j]!=mp[i+1][j])
			{
				swap(mp[i][j],mp[i+1][j]);
				ans[stp][0]=i,ans[stp][1]=j,ans[stp][2]=1;
				Del(); dfs(stp+1);
				memcpy(mp,tmp[stp],sizeof mp);
			}
			if(i!=1&&!mp[i-1][j])
			{
				swap(mp[i][j],mp[i-1][j]);
				ans[stp][0]=i,ans[stp][1]=j,ans[stp][2]=-1;
				Del(); dfs(stp+1);
				memcpy(mp,tmp[stp],sizeof mp);
			}
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=5; ++i)
		for(int j=1,x; scanf("%d",&mp[i][j]),mp[i][j]; ++j);
	dfs(1); puts("-1");
}