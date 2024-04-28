#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,A[maxn],B[maxn],C1[maxn],dp[maxn],
C2[maxn],C3[maxn],ans,st,nxt[maxn],las;
void ToMax1(int x,int y){while(x<=1e6+5)C1[x]=max(y,C1[x]),x+=x&-x;}
int GetMax1(int x,int y=0){while(x)y=max(C1[x],y),x^=x&-x;return y;}
void ToMax2(int x,int y){while(x)C2[x]=max(y,C2[x]),x^=x&-x;}
int GetMax2(int x,int y=0){while(x<=1e6+5)y=max(C2[x],y),x+=x&-x;return y;}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=k;++i)
	{
		char tmp[2];
		scanf("%s",&tmp);
		if(tmp[0]=='<')B[i]=-1;
		if(tmp[0]=='=')B[i]=00;
		if(tmp[0]=='>')B[i]=+1;
	}
	for(int i=k+1;i<=n;++i)
		B[i]=B[(i-1)%k+1];
	for(int i=1;i<=n;++i)
	{
		dp[i]=max(GetMax1(A[i]-1)+1,C3[A[i]]+1);
		dp[i]=max(GetMax2(A[i]+1)+1,dp[i]);
		if(B[dp[i]]==-1)ToMax1(A[i],dp[i]);
		if(B[dp[i]]==00)C3[A[i]]=dp[i];
		if(B[dp[i]]==+1)ToMax2(A[i],dp[i]);
		if(dp[i]>ans)ans=dp[i];
	}
	printf("%d\n",ans);
	for(int i=n;i;--i)
		if(dp[i]==ans)
		{
			if(!las)st=las=i,--ans;
			else
			{
					 if(B[ans]==-1&&A[i]<A[las])nxt[i]=las,st=las=i,--ans;
				else if(B[ans]==0&&A[i]==A[las])nxt[i]=las,st=las=i,--ans;
				else if(B[ans]==+1&&A[i]>A[las])nxt[i]=las,st=las=i,--ans;
			}
		}
	for(int i=st;i;i=nxt[i])printf("%d ",A[i]);
}
