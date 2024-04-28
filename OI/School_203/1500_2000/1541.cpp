#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,k,A[N],B[N],cnt,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=m;++i)
		scanf("%d",&x),B[x]=1;
	for(int i=1,x;i<=k;++i)
		scanf("%d",&x),A[x]=1;
	for(int i=1;i<=n;++i)
	{
		if(A[i])
		{
			if(B[i])B[i]=0;
			else 
			{
				if(B[i-1])++ans;
				else if(B[i+1])B[i+1]=0;
			}
		}
		if(!B[i])++ans;
	}
	printf("%d\n",n-ans);
}