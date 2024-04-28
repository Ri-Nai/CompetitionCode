#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char s[105][105];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(i!=n&&s[i][j]==s[i+1][j]&&s[i][j]=='.')++ans;
			if(j!=m&&s[i][j]==s[i][j+1]&&s[i][j]=='.')++ans;
		}
	printf("%d\n",ans);
}