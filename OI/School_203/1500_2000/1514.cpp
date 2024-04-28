#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ago;
int n,C,D,to[N],tot,len[N],blg[N];
ago A,B,L=1;
ago gcd(ago	a,ago b)
{
	return b?gcd(b,a%b):a;
}
bool vis[N];
void solve(int u)
{
	++tot;
	for(int v=u;!vis[v];vis[v]=1,v=to[v])
		++len[blg[v]=tot];
}
ago	Get(ago pos)
{
	if(!pos)return 0;
	return (pos-1)/L+1;
}
int main()
{
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;++i)
		scanf("%d",&to[i]);
	for(int i=1;i<=n;++i)if(!vis[i])solve(i);
	for(int i=C+1;i<=n-D;++i)
		L=L/gcd(len[blg[i]],L)*len[blg[i]];
	printf("%lld\n",Get(B)-Get(A-1));
}
//1开始有答案
//