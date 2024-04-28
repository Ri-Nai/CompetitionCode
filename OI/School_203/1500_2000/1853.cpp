#include<bits/stdc++.h>
using namespace std;
const int N=1e6+35;
typedef long long ago;
int n,ls[N],rs[N],fa[N];
struct Num
{
	int n,len;
	Num(){n=0;len=0;}
	Num(int _,int __){n=_,len=__;}
	bool operator <(const Num &_)const
	{
		ago n1=n,n2=_.n;
		int df=len-_.len;
		if(df<-32)return 1;
		if(df>32)return 0;
		if(df<0)n2<<=-df;
		else n1<<=df;
		return n1<n2;
	}
	void show()
	{
		char s[50],k=0;
		int tmp=n;
		do s[++k]=tmp&1^48,tmp>>=1;while(tmp);
		while(k)putchar(s[k--]);
		for(int i=1;i<=len;++i)putchar('0');
	}
}ans;
Num dfs(int u)
{
	if(u<0)return Num(-u,0);
	Num lsm=dfs(ls[u]),rsm=dfs(rs[u]);
	lsm=max(lsm,rsm);
	return Num(lsm.n,lsm.len+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&ls[i],&rs[i]);
		if(ls[i]>0)fa[ls[i]]=i;
		if(rs[i]>0)fa[rs[i]]=i;
	}
	int rt=0;while(fa[++rt]);
	ans=dfs(rt);ans.show();
}