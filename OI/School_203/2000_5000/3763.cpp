#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
char s[N];
int n,top,to[N],stk[N];
void solve(int p,int l,int r)
{
	if(!p)
	{
		int id=l;
		while(id<=r)
		{
			if(to[id])
			{
				solve(p^1,id+1,to[id]-1);
				id=to[id]+1;
			}
			else putchar(s[id++]);
		}
	}
	else
	{
		int id=r;
		while(id>=l)
		{
			if(to[id])
			{
				solve(p^1,to[id]+1,id-1);
				id=to[id]-1;
			}
			else putchar(s[id--]);
		}
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')stk[++top]=i;
		if(s[i]==')')
		{
			to[stk[top]]=i;
			to[i]=stk[top--];
		}
	}
	solve(0,1,n);
}