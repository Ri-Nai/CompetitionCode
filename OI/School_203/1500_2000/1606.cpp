#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,A[N],C[N];
long long ans;
void Add(int x,int y)
{
	while(x<=n)C[x]+=y,x+=x&-x;
}
int Sum(int x)
{
	int res=0;
	while(x)res+=C[x],x-=x&-x;
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;++i)
	{
		if(i<n&&A[i]>A[i+1])
		{
			int bg=i,ed;
			while(i<n&&A[i]>A[i+1])++i;ed=i;
			for(int j=bg,k=ed;j<k;++j,--k)swap(A[j],A[k]);
			++ans;
		}
	}
	for(int i=1;i<=n;++i)
	{
		Add(A[i],1);
		ans+=i-Sum(A[i]);
	}
	printf("%lld\n",ans);
}
/*
7

1 7 2 5 6 3 4

1 2 7 5 3 6 4 +2

1 2 3 5 7 4 6 +2

1 2 3 5 4 7 6 +1

1 2 3 4 5 6 7 +2

*/