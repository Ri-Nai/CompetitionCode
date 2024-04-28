#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a,_i=b;i<=_i;++i)
const int N=1005;
int n,m,mn=1e9,x,y;
void put(int n,char c){while(--n)putchar(c);}
void solve()
{
	FOR(i,1,n)FOR(j,1,m)
	{
		int w;scanf("%d",&w);
		if((i+j&1)&&w<mn)mn=w,x=i,y=j;
	}
	FOR(i,1,n>>1)
	{
		int now=(i<<1)-1;
		if(now!=x&&now+1!=x)
		{
			put(m,now<x?'R':'L');
			putchar('D');
			put(m,now<x?'L':'R');
		}
		else
		{
			bool lqr=0;
			FOR(j,1,m)
			{
				if(j!=y)putchar((lqr^=1)?'D':'U');
				if(j!=m)putchar('R');
			}
		}
		if(now+1!=n)putchar('D');
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n&1)FOR(i,1,n)
	{
		put(m,(i&1)?'R':'L');
		if(i!=n)putchar('D');
	}
	else if(m&1)FOR(i,1,m)
	{
		put(n,(i&1)?'D':'U');
		if(i!=m)putchar('R');
	}
	else solve();
}