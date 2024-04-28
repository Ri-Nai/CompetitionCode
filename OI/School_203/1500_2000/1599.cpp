#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,tot;
long long ans=0;
struct node
{
	int u,v;
	bool operator <(const node &_)const
	{
		return u<_.u;
	}
}A[N<<1];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		if(u>v)
			A[++tot]=(node){u,1},
			A[++tot]=(node){v,0};
	}
	sort(A+1,A+tot+1);
	int lqr=0,top=0,l;
	for(int i=1;i<=tot;++i)
	{
		if(A[i].v)
		{
			if(!--top)ans+=A[i].u-l;
		}
		else if(!top++)l=A[i].u;
	}
	printf("%lld\n",2ll*ans+m);
}