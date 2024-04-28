#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<int>E[maxn];
map<string,int>mp;
int n,tot,dp[maxn][2];
void dfs(int now)
{
	dp[now][0]=0;dp[now][1]=1;
	for(int i=0;i<E[now].size();++i)
	{
		int nxt=E[now][i];dfs(nxt);
		dp[now][0]+=dp[nxt][1];
		dp[now][1]+=dp[nxt][0];
	}
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		string t1,t2;
		cin>>t1;mp[t1]=++tot;
		for(int i=2;i<=n;++i)
		{
			cin>>t1>>t2;
			if(!mp[t1])mp[t1]=++tot;
			if(!mp[t2])mp[t2]=++tot;
			E[mp[t2]].push_back(mp[t1]);
		}
		dfs(1);
	}
}