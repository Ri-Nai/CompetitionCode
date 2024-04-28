//不开long long见祖宗
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct CP
{
	long long v;int id;
	bool operator <(const CP &_)const
	{
		return v>_.v;
	}
};
priority_queue<CP>Q;
int n,k,tot,stk[N],mn[N<<2],top;
long long ans[N],B[N],A[N];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
int Build(int L=1,int R=n,int p=1)
{
	if(L==R)return mn[p]=B[L];int mid=L+R>>1;
	return mn[p]=min(Build(L,mid,p<<1),Build(mid+1,R,p<<1|1));
}
int Query(int l,long long x,int L=1,int R=n,int p=1)
{
	if(R<l)return -1;
	if(mn[p]>x)return -1;
	if(L==R)return L;
	int mid=L+R>>1;
	int k=Query(l,x,L,mid,p<<1);
	if(~k)return k;
	return Query(l,x,mid+1,R,p<<1|1);
}
bool dfs(int now,long long sum)
{
	if(!sum)
	{
		if(!--tot)
		{
			for(int i=1;i<=top;++i)
				printf("%d ",stk[i]);
			return 1;
		}
		return 0;
	}
	for(;now<=n;++now,--top)
	{
		now=Query(now,sum);
		if(now==-1)return 0;stk[++top]=now;
		if(dfs(now+1,sum-B[now]))return 1;
	}
	return 0;
}
int main()
{
	n=rd();k=rd()-1;
	if(!k)return !puts("0");
	for(int i=1;i<=n;++i)B[i]=A[i]=rd();
	sort(A+1,A+n+1);Q.push({A[1],1});
	for(int i=1;i<=k;++i)
	{
		ans[i]=Q.top().v;
		int p=Q.top().id;Q.pop();
		if(p==n)continue;
		Q.push({ans[i]-A[p]+A[p+1],p+1});
		Q.push({ans[i]+A[p+1],p+1});//排序后的id
	}
	printf("%lld\n",ans[k]);
	while(ans[k-tot]==ans[k])++tot;//重复的
	Build();dfs(1,ans[k]);
}