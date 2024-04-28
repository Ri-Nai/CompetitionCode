#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,A[N],ans[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	for(int i=1;i<=A[n]+1;++i)
	{
		int cnt=0,now=0,pre=0,nxt=1e8+5;
		for(int j=1;j<=n;++j,++cnt,pre=now)
		{
			now=A[j]/i;
			if(now)nxt=min(nxt,A[j]/now);
			if(j==1)continue;
			if(now!=pre)
			{
				if(!ans[cnt])ans[cnt]=i;
				cnt=0;
			}
		}
		if(!ans[cnt])ans[cnt]=i;
		i=nxt;
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]?ans[i]:-1);
}