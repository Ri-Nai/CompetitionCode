#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int C[N],A[N],n;
long long ans;
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x^=x&-x;
	return res;
}
vector<int>E[N];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
int main()
{
	n=rd();
	for(int i=1,x;i<=n;++i)
		x=min(n,rd()+1),E[x].push_back(i);
	for(int i=1;i<=n;++i)
	{
		printf("%lld\n",ans);
		for(int j=0;j<E[i].size();++j)Add(E[i][j],1);
		for(int j=0;j<E[i].size();++j)ans+=E[i][j]-Sum(E[i][j]);
	}
}