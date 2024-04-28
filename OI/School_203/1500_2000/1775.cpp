#include<bits/stdc++.h>
using namespace std;
bool mark[1<<21];
int main()
{
	int n,m,res=0;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		mark[(1<<u-1)|(1<<v-1)]=1;
	}
	for(int i=0;i<(1<<n);++i)
	{
		if(mark[i])
		{
			for(int j=0;j<n;++j)
				if(!(1<<j&i))mark[i|1<<j]=1;
		}
		else ++res;
	}
	printf("%d\n",res);
}