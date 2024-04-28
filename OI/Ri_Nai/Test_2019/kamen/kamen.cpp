#include<cstdio>
#define Fasdasd
int mp[30005][35],r,c;
char tmp[35],to[3]={'O','.','X'};
inline int pd(const int &x,const int &y)
{
	if(x-1>=1&&!mp[y][x-1]&&!mp[y+1][x-1])
		return -1;
	if(x+1<=c&&!mp[y][x+1]&&!mp[y+1][x+1])
		return 1;
	return 0;
}
void solve()
{
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i)
	{
		scanf("%s",tmp+1);
		for(int j=1;j<=c;++j)
			if(tmp[j]=='X')
				mp[i][j]=1;
	}
	for(int i=1,j;i<=c;++i)
		mp[r+1][i]=1;
	int n,x,now;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		int now=1;
		while(!mp[now+1][x])++now;
		while(1)
		{
			if(mp[now+1][x]==-1)
			{
				int state=pd(x,now);
				if(!state)
				{
					mp[now][x]=-1;
					break;
				}
				x+=state;
				while(!mp[now+1][x])++now;
			}
			else 
			{
				mp[now][x]=-1;
				break;
			}
		}
	}
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
			putchar(to[mp[i][j]+1]);
		putchar('\n');
	}
}
int main()
{
	#ifndef F
	freopen("kamen.in","r",stdin);
	freopen("kamen.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
