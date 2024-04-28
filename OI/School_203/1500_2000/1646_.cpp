#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a,b,sum[50],dp[50],ans;
LL solve(LL x)
{
	if(x==2)return 1;
	for(int i=1;i<=x;++i)
		if(x%i)return solve(i)+1;
}
int main()
{

	cin>>a>>b;
	while(a<=b)ans+=solve(a++);
	cout<<ans<<endl;
}