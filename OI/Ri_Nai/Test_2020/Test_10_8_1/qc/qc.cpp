#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e6+5;
typedef long long LL;
LL S,ans[N],Sum[N],Cnt[N];
int n,m,W[N],V[N],B[N],len;
bool vis[N];
struct Que
{
	int L,R;
	bool operator <(const Que &_)const
	{
		return R<_.R;
	}
	void read(){scanf("%d%d",&L,&R);}
}Q[N];
LL Get(int T)
{
	if(vis[T])return ans[T];
	vis[T]=1;
	int now=1;
	LL res=-S;
	for(int i=1;i<=m;++i)
	{
		int L=Q[i].L,R=Q[i].R;
		while(now<=R)
		{
			Sum[now]=Sum[now-1];
			Cnt[now]=Cnt[now-1];
			if(W[now]>=T)
				Sum[now]+=V[now],++Cnt[now];
			++now;
		}
		res+=(Cnt[R]-Cnt[L-1])*(Sum[R]-Sum[Q[i].L-1]);
	}
	if(res<0)res=-res;
	return ans[T]=res;
}
int main()
{
	// FILE("qc");
	cin>>n>>m>>S;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&W[i],&V[i]),B[i]=W[i];
	for(int i=1;i<=m;++i)Q[i].read();
	sort(Q+1,Q+m+1);sort(B+1,B+n+1);
	len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)W[i]=lower_bound(B+1,B+len+1,W[i])-B;
	int L=1,R=len+1,res=1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(mid==1||Get(mid-1)>Get(mid))
			L=mid+1,res=mid;
		else R=mid-1;
	}
	printf("%lld\n",Get(res));
	FCLS();
}
/*
单峰性

*/