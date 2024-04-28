#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,fa[N],pre[N][26],id[N],fail[N],tot,ans[N],Q[N],L,R,pd[N];
char s[N],o[2],tmp[N];
void Build_Fail()
{
	for(int i=0;i<26;++i)
	{
		int &nxt=pre[0][i];
		if(nxt)fail[nxt]=0,Q[++R]=nxt;
	}
	while(L^R)
	{
		int now=Q[++L];
		for(int i=0;i<26;++i)
		{
			int &nxt=pre[now][i];
			if(nxt)fail[nxt]=pre[fail[now]][i],Q[++R]=nxt;
			else nxt=pre[fail[now]][i];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s %d",o,&fa[i]),s[i]=*o-'A';
	for(int i=1;i<=m;++i)
	{
		scanf("%s",tmp+1);
		int len=strlen(tmp+1),&now=id[i];
		for(int i=len;i;--i)
		{
			int c=tmp[i]-'A',&nxt=pre[now][c];
			if(!nxt)nxt=++tot;now=nxt;
		}
	}
	Build_Fail();
	for(int i=1;i<=n;++i)++ans[pd[i]=pre[pd[fa[i]]][s[i]]];
	for(int i=R;i;--i)ans[fail[Q[i]]]+=ans[Q[i]];//小后缀转移至大后缀
	for(int i=1;i<=m;++i)printf("%d\n",ans[id[i]]);
}