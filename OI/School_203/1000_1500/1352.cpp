#include<queue>
#include<cstdio>
#include<vector>
#include<functional>
const int maxn=10005;
int n,m,A[maxn];
std::priority_queue<int,std::vector<int>,std::greater<int> >Q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1;i<=m;++i)Q.push(A[i]);
	for(int i=m+1;i<=n;++i)
		Q.push(A[i]+Q.top()),Q.pop();
	while(Q.size()>1)Q.pop();
	printf("%d\n",Q.top());
}