#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int A[N],n,P,mod,to[N];
char s[N];
struct pr
{
	LL k,b;pr(){k=b=0;}
	pr(LL _,LL __){k=_,b=__;}
};
void in_put()
{
	scanf("%s",s);
	scanf("%d%d",&P,&mod);
	int len=strlen(s),now=0;
	while(now<len)
	{
		if(isdigit(s[now]))
		{
			int res=s[now++]-'0';
			while(now<len&&isdigit(s[now]))
				(res=res*10+s[now++]-'0')%=mod;
			A[++n]=res;
			continue;
		}
		if(s[now]=='+')A[++n]=-1;
		if(s[now]=='*')A[++n]=-2;
		if(s[now]=='(')A[++n]=-3;
		if(s[now]==')')A[++n]=-4;
		if(s[now]=='x')A[++n]=-5;
		if(s[now]=='-')A[++n]=-6;
		++now;
	}
	stack<int>S;
	for(int i=1;i<=n;++i)
	{
		if(A[i]==-3)S.push(i);
		if(A[i]==-4)to[S.top()]=i,S.pop();
	}
}
inline void Plus(pr &p1,const pr &p2)
{
	(p1.b+=p2.b)%=mod;(p1.k+=p2.k)%=mod;
}
inline void Prod(pr &p1,const pr &p2)
{
	p1.k=(p1.k*p2.b+p2.k*p1.b)%mod;
	p1.b=p1.b*p2.b%mod;
}
inline void work(int pre,pr &res,pr &now,const pr &tmp)
{
	if(pre==1)Prod(now,tmp);
	if(pre==0)Plus(res,now),now=tmp;
	if(pre==-1)Plus(res,now),now=pr(-tmp.k+mod,-tmp.b+mod);
}
pr solve(int L,int R)
{
	pr res=pr(),now=pr();
	int pre=0;
	for(int i=L;i<=R;++i)
	{
		if(to[i])
			work(pre,res,now,solve(i+1,to[i]-1)),i=to[i];
		else
		{
			if(A[i]==-5)work(pre,res,now,pr(1,0));
			else if(A[i]==-1)pre=0;
			else if(A[i]==-2)pre=1;
			else if(A[i]==-6)pre=-1;
			else work(pre,res,now,pr(0,A[i]));
		}
	}
	Plus(res,now);
	return res;
}
int main()
{
	in_put();pr res=solve(1,n);
	for(int i=0;i<=mod;++i)
		if((1ll*i*res.k+res.b)%mod==P)
		{
			printf("%d\n",i);break;
		}
}