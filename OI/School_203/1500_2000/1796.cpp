#include<bits/stdc++.h>
using namespace std;
const int N=1.5e6+6;
int n,Q,nxt[N][26][2],len,tot[2],L[N],R[N],stk[N],num;
char tmp[N];string s[N];vector<int>to[N];
int move(int S,int &now,char c,bool p)
{
	c-='a';
	if(!nxt[now][c][S])
		if(!p)nxt[now][c][S]=++tot[S];
		else return now=-1;
	return now=nxt[now][c][S];
}
void dfs(int now)
{
	L[now]=++num;
	for(int i=0;i<26;++i)
		if(nxt[now][i][1])dfs(nxt[now][i][1]);
	R[now]=num;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",tmp);
		len=strlen(tmp);
		s[i]=string(tmp);
		int l=0,r=0;
		for(int j=0;j<len;++j)move(0,l,tmp[j],0);
		for(int j=len-1;~j;--j)move(1,r,tmp[j],0);
	}
	dfs(0);
	for(int i=1;i<=n;++i)
	{
		int l=0,r=0,top=0;
		for(int j=0;j<s[i].size();++j)
			stk[++top]=move(0,l,s[i][j],0);
		to[stk[top--]].push_back(L[0]);
		for(int j=s[i].size()-1;~j;--j)
			to[stk[top--]].push_back(L[move(1,r,s[i][j],0)]);
	}
	for(int i=0;i<=tot[0];++i)
		sort(to[i].begin(),to[i].end());
	for(int i=1;i<=Q;++i)
	{
		scanf("%s",tmp);
		len=strlen(tmp);
		int l=0,r=0;
		for(int j=0;;++j)
			if(tmp[j]=='*'||move(0,l,tmp[j],1)==-1)break;
		if(l==-1){puts("0");continue;}
		for(int j=len-1;;--j)
			if(tmp[j]=='*'||move(1,r,tmp[j],1)==-1)break;
		if(r==-1){puts("0");continue;}
		vector<int>::iterator lid,rid;
		rid=upper_bound(to[l].begin(),to[l].end(),R[r]);
		lid=lower_bound(to[l].begin(),to[l].end(),L[r]);
		printf("%d\n",rid-lid);
	}
}