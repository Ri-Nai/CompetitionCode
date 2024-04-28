#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,c,m,A[maxn],last[maxn],last_2[maxn],ans[maxn];
struct BIT
{
	int C[maxn];
	void Add(int x,int y){while(x<=n)C[x]+=y,x+=x&-x;}
	int sum(int x,int res=0){while(x)res+=C[x],x-=x&-x;return res;}
}Tree;
struct $
{
	int id,l;	
};
vector<$>E[maxn];
int main()
{
	scanf("%d%d%d",&n,&c,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=1,l,r;i<=m;++i)
		scanf("%d%d",&l,&r),
		E[r].push_back(($){i,l});
	for(int i=1;i<=n;++i)
	{
		if(!last[A[i]])last[A[i]]=i;
		else
		{
			if(last_2[A[i]])Tree.Add(last_2[A[i]],-1);
			Tree.Add(last[A[i]],1);
			last_2[A[i]]=last[A[i]];
			last[A[i]]=i;
		}
		for(int j=0;j<E[i].size();++j)
		{
			ans[E[i][j].id]=Tree.sum(i)-Tree.sum(E[i][j].l-1);
			if(ans[E[i][j].id]<0)ans[E[i][j].id]=0;
		}
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
}