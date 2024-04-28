#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
map<int,int>mp;
int A[N],B[N],n;
int main()
{
	scanf("%d",&n);int ans=1,mx=0,k;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		B[i]=B[i-1];
		if(i>1)
		{
			if(A[i]>A[i-1])++B[i];
			if(A[i]<A[i-1])--B[i];
			if(!B[i]&&A[i]==A[1])++ans;
			if(B[i])
			{
				if((A[i]-A[1])%B[i]==0)
					++mp[(A[i]-A[1])/B[i]];
			}
		}
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
	{
		if(it->second>mx)mx=it->second,k=it->first;
	}
	printf("%d\n%d\n",mx+ans,k);
}