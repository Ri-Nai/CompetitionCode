#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
LL solve(LL x)
{
	LL res=0;
	for(int i=1;i;++i)
	{
		LL tmp=1ll*i*i;
		if(tmp*i>x)break;
		res+=(x-tmp*i)/tmp+1;
	}
	return res;
}
int main()
{
	cin>>a>>b;
	cout<<solve(b)-solve(a-1);
}