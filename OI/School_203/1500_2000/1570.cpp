#include<bits/stdc++.h>
using namespace std;
int n,m;
set<string>S;
char s[1005][1005];
string T[1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	int i;
	for(i=n;i>=1;--i)
	{
		S.clear();
		bool flag=0;
		for(int j=1;j<=m;++j)
		{
			T[j]+=s[i][j];
			//cout<<T[j]<<endl;
			if(flag)continue;
			if(S.find(T[j])!=S.end())flag=1;
			else S.insert(T[j]);
		}
		//cout<<flag<<endl;
		if(!flag)break;
	}
	printf("%d\n",i-1);
}