#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=55;
int n;db A[N];
db dfs()
{
	char c;db B[N];
	int tot=0;
	bool flag=0;
	while(1)
	{
		c=getchar();
		if(c=='(')B[++tot]=dfs();
		else if(c=='?')B[++tot]=A[1];
		else if(c=='+')flag=0;
		else if(c=='*')flag=1;
		else if(c==')')
		{
			db sum=0;
			for(int i=1;i<=tot;++i)sum+=B[i];
			sum=min(sum,A[tot]);
			if(!flag)return sum;
			sort(B+1,B+tot+1);int now=1;db ans=1;
			for(;now<=tot&&sum/(tot-now+1)>B[now];++now)
				ans*=B[now],sum-=B[now];
			ans*=pow(sum/(tot-now+1),tot-now+1);
			return ans;
		}
		else return B[1];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf",&A[i]);
	if(getchar()!='\n')getchar();printf("%.0f\n",dfs());
}