#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,int>mp;
LL a,b,sum[50],dp[50];
int tot,ans[50];
int work(int x)
{
	if(ans[x])return ans[x];
	if(x==2)return ans[x]=1;
	for(int i=2;i<=x;++i)
		if(x%i)return ans[x]=work(i)+1;
}
LL solve(LL x)
{
	memset(dp,0,sizeof dp);
	for(int i=tot;i>=1;--i)
	{
		dp[i]=x/sum[i];
		for(int j=tot;j>i;--j)
			dp[i]-=dp[j];
	}
	LL res=0;
	for(int i=1;i<=tot;++i)
	{
 		if(dp[i]&&sum[i]==2)--res;
		res+=(work(mp[sum[i]])+1)*(dp[i]);
	}
	return res;
}
int main()
{
mp[1]=2;
mp[2]=3;
mp[6]=4;
mp[12]=5;
mp[60]=6;
mp[60]=7;
mp[420]=8;
mp[840]=9;
mp[2520]=10;
mp[2520]=11;
mp[27720]=12;
mp[27720]=13;
mp[360360]=14;
mp[360360]=15;
mp[360360]=16;
mp[720720]=17;
mp[12252240]=18;
mp[12252240]=19;
mp[232792560]=20;
mp[232792560]=21;
mp[232792560]=22;
mp[232792560]=23;
mp[5354228880]=24;
mp[5354228880]=25;
mp[26771144400]=26;
mp[26771144400]=27;
mp[80313433200]=28;
mp[80313433200]=29;
mp[2329089562800]=30;
mp[2329089562800]=31;
mp[72201776446800]=32;
mp[144403552893600]=33;
mp[144403552893600]=34;
mp[144403552893600]=35;
mp[144403552893600]=36;
mp[144403552893600]=37;
mp[5342931457063200]=38;
mp[5342931457063200]=39;
mp[5342931457063200]=40;
mp[5342931457063200]=41;
mp[219060189739591200]=42;
mp[219060189739591200]=43;
	for(map<LL,int>::iterator it=mp.begin();it!=mp.end();++it)
		sum[++tot]=it->first;
	cin>>a>>b;
	cout<<solve(b)-solve(a-1)<<endl;
}