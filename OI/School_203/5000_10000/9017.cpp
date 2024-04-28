#include<bits/stdc++.h>
using namespace std;
#define RG register
const int N=2e7+5;
int n,b,A,c,p,T,now,num,k,cnt[N],top;
long long ans;
int main()
{
	cin>>n>>k>>T>>A>>b>>c>>p;
	now=k;cnt[k]=1;
	for(RG int i=1;i<=n;++i)
	{
		A=(1ll*A*b+c)%p;
		if(A>=T)
		{
			++cnt[++now];
			num+=cnt[now-k];
		}
		else ++cnt[now];
		ans+=num;
	}
	printf("%lld\n",ans);
}
/*
5 2 100 11 124 7 300
*/