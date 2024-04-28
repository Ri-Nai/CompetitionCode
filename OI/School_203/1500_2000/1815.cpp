#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,A[N];
char s[15][N];
bool dp[15][N];
vector<pair<int,int> >V;
int main()
{
	scanf("%d",&n);
	for(int i=10;i>=1;--i)
		scanf("%s",s[i]+1);
	dp[1][1]=1;
	for(int i=2;i<=n;++i)
		for(int j=1;j<=10;++j)
		{
			if(s[j][i]=='X')continue;
			if(j==1)dp[j][i]=dp[j][i-1]|dp[j+1][i-1];
			else if(j==10)dp[j][i]=dp[j][i-1]|dp[j-1][i-1];
			else dp[j][i]=dp[j-1][i-1]|dp[j+1][i-1];

		}
	int pos;
	for(int i=1;i<=10;++i)
		if(dp[i][n]&&(pos=i))break;
	A[n]=pos;A[1]=1;
	for(int i=n-1;i>1;--i)
	{
		if(pos==1)
		{
			if(!dp[pos][i])++pos;
		}
		else if(pos==10)
		{
			if(!dp[pos][i])--pos;
		}
		else 
		{
			if(dp[pos-1][i])--pos;
			else ++pos;
		}
		A[i]=pos;
	}
	int bg=0,len;
	for(int i=2;i<=n;++i)
	{
		if(A[i]!=1&&A[i]>=A[i-1])
		{
			if(!bg)bg=i-2,len=1;
			else ++len;
		}
		else
		{
			if(bg)V.push_back(make_pair(bg,len)),bg=0;
		}
	}
	if(bg)V.push_back(make_pair(bg,len)),bg=0;
	printf("%d\n",V.size());
	for(int i=0;i<V.size();++i)
	{
		printf("%d %d\n",V[i].first,V[i].second);
	}
}