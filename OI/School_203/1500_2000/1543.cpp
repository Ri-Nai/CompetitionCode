#include<bits/stdc++.h>
using namespace std;
const int N=12,M=2e6;
int X[N],Y[N],R[N],n,stk[N<<1],mn=1e9,mx;
long long ans;
struct node
{
	int now,lqr;
	bool operator < (node _)const
	{
		return now==_.now?lqr<_.lqr:now<_.now;
	}
}A[N<<1];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&X[i],&Y[i],&R[i]);
		mn=min(Y[i],mn);mx=max(mx,Y[i]+R[i]);
	}
	for(register int i=mn;i<=mx;++i)
	{
		register int tot=0,top=0,p=0;
		for(register int j=1;j<=n;++j)
		{
			if(Y[j]<=i&&Y[j]+R[j]>i)
			{
				A[++tot]=(node){X[j],0};
				A[++tot]=(node){X[j]+R[j]+Y[j]-i-1,1};
			}
		}
		sort(A+1,A+tot+1);
		for(register node *it=A+1;it!=A+tot+1;++it)
		{
			int now=it->now,lqr=it->lqr;
			if(!lqr)stk[++top]=now;
			else
			{
				int pre=stk[top--],sum=now-pre+now-pre+1;
				if(p)ans+=sum;
				else ans-=sum;
			}
			p^=1;
		}
	}
	printf("%.1f\n",ans/2.0);
}