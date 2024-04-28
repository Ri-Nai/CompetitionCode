#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,cnt[N],now[N],ans,num,pos;
bool mark[N];
struct node
{
	int id,lqr;
	void read()
	{
		char s[10];scanf("%s",s);
		lqr=*s=='s'?-1:1;id=0;
		for(int i=1;s[i];++i)
			id=(id<<1)+(id<<3)+(s[i]^48);
		now[id]=min(now[id],cnt[id]-=lqr);
	}
}A[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)A[i].read();
	for(int i=1;i<=n;++i)
	{
		int id=A[i].id;
		if(mark[id])continue;
		mark[id]=1;
		if(!now[id]&&!cnt[id])++num;
	}
	pos=1,ans=num;
	for(int i=1;i<n;++i)
	{
		int id=A[i].id,lqr=A[i].lqr;
		if(cnt[id])continue;
		if(!now[id])--num;
		now[id]+=lqr;
		if(!now[id])++num;
		if(num>ans)pos=i+1,ans=num;
	}
	printf("%d %d\n",pos,ans);
}
/*
尺取+括号匹配
s='(' e=')'
((()()()()))

当前插入和删除的一定是同一个括号

只是把首个括号移到最右侧
或者说向右直接插括号
要记录每个序列在哪个位置的时候是可以合法的

)))) ()()()()()((((

)))) () | () | () | () | () | (((()))) |

())()()()(
对于这种情况//

一定是右括号移到最后的左括号后边使其合法

将其相反即可

'('='+',')'='-'记录原先最小的值
再')'='+','('='-'合法++
*/