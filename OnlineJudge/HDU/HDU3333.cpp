#include<map>
#include<cstdio>
#include<vector>
#include<cstring>
#define LL long long
const int maxn=1e5+5;
struct ${int l,id;};
int n,m,A[maxn];
LL ans[maxn],C[maxn];
std::map<int,int>mp;
std::vector<$>V[maxn];
void Add(int x,int y){while(x<maxn)C[x]+=y,x+=x&-x;}
LL sum(int x){LL res=0;while(x)res+=C[x],x-=x&-x;return res;}
void CLEAR()
{
	mp.clear();memset(C,0,sizeof C);
	for(int i=1;i<maxn;++i)V[i].clear();
}
void solve()
{
	CLEAR();scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;++i)
		scanf("%d%d",&l,&r),V[r].push_back(($){l,i});
	for(int i=1;i<=n;++i)
	{
		if(mp[A[i]])Add(mp[A[i]],-A[i]);
		mp[A[i]]=i,Add(i,A[i]);
		for(int j=0;j<V[i].size();++j)
			ans[V[i][j].id]=sum(i)-sum(V[i][j].l-1);
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)solve();
}