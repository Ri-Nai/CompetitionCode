#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=10005;
int n,m,k,MxT[N],A[M],B[M],T[N],t[M],D[N],S[N],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;++i)scanf("%d",&D[i]);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&t[i],&A[i],&B[i]);
		MxT[A[i]]=max(MxT[A[i]],t[i]);
		++S[B[i]];
	}
	for(int i=1;i<=n;++i)
		S[i]+=S[i-1],T[i+1]=max(T[i],MxT[i])+D[i];
	for(int i=1;i<=m;++i)ans+=T[B[i]]-t[i];//最坏情况
	for(int pos,mx,mxp;k--;)
	{
		pos=n;mx=mxp=0;
		for(int i=n-1;i;--i)
		{
			if(MxT[i+1]>=max(MxT[i],T[i])+D[i])pos=i+1;//找到后一个需要停下来等人的点
			if(D[i]&&S[pos]-S[i]>mx)mx=S[pos]-S[mxp=i];//能拯救的最多人数
		}
		if(!mxp)break;
		ans-=mx;--D[mxp];
		for(int i=mxp;i<n;++i)
			T[i+1]=max(T[i],MxT[i])+D[i];
	}
	printf("%d\n",ans);
}