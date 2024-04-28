#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N][N];
int n,m,X[N*N],Y[N*N];
void solve(char c)
{
	int tot=0;long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]==c)X[++tot]=i+j,Y[tot]=i-j;
	sort(X+1,X+tot+1);sort(Y+1,Y+tot+1);
	for(int i=1;i<=tot;++i)
		ans+=1ll*(2*i-tot-1)*(X[i]+Y[i]);
	printf("%lld ",ans/2);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	solve('M');solve('S');
}