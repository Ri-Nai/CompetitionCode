#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,X[N],Y[N],Z[N];
int dp[N],ans,id[N],C[N];
inline void ToMax(int &x,int y) {x<y &&(x=y);}
bool cmp1(int a,int b) {return Y[a]<Y[b];}
bool cmp2(int a,int b) {return X[a]<X[b];}
void Del(int x) {while(x<N)C[x]=0,x+=x&-x;}
void Upd(int x,int y) {while(x<N)ToMax(C[x],y),x+=x&-x;}
int Get(int x)
{
	int res=0;
	while(x)ToMax(res,C[x]),x-=x&-x;
	return res;
}
void solve(int L,int R)
{
	if(L==R)return ToMax(dp[L],1);
	int mid=L+R>>1; solve(L,mid);
	for(int i=L; i<=R; ++i)id[i]=i;
	sort(id+L,id+mid+1,cmp1);
	sort(id+mid+1,id+R+1,cmp2);
	for(int i=mid+1,j=L; i<=R; ++i)
	{
		while(j<=mid&&Y[id[j]]<=X[id[i]])
			Upd(X[id[j]],dp[id[j]]),++j;
		ToMax(dp[id[i]],Get(Z[id[i]])+1);
	}
	for(int i=L; i<=mid; ++i)Del(X[i]);
	solve(mid+1,R);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&X[i]),Y[i]=Z[i]=X[i];
	for(int i=1,x,y; i<=m; ++i)
		scanf("%d%d",&x,&y),ToMax(Y[x],y),Z[x]=min(Z[x],y);
	solve(1,n);
	for(int i=1; i<=n; ++i)ToMax(ans,dp[i]);
	printf("%d\n",ans);
}