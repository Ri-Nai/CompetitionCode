#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+5;
int n,m,A[N];
bool check(LL mid)
{
	int res=0;
	for(int i=1;i<=m;++i)
		res+=A[i]/mid+(A[i]%mid!=0);
	return res<=n;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		scanf("%d",&A[i]);
	LL l=1,r=1e9,ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
			ans=mid,
			r=mid-1;
		else l=mid+1;
	}cout<<ans<<endl;
}