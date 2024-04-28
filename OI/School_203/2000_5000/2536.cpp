#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef double db;
const db eps=1e-7;
struct DAY
{
	db A,B,Rt,x,y,k;
	int id;
	db Get(DAY _) {return _.x*A+_.y*B;}
	void Get(db p) {y=p/(A*Rt+B); x=y*Rt;}
	void read(int i) {scanf("%lf%lf%lf",&A,&B,&Rt); k=-A/B; id=i;}
	db Slp(DAY _)
	{
		return fabs(x-_.x)<eps?1e18:(y-_.y)/(x-_.x);
	}
} P[N],Q[N],C[N];
int n; db dp[N];
bool cmp(DAY _,DAY __) {return _.k<__.k;}
void Solve(int L,int R)
{
	if(L==R)return P[L].Get(dp[L]=max(dp[L],dp[L-1]));
	int mid=L+R>>1,tp=0,l=L,r=mid+1;
	for(int i=L; i<=R; ++i)C[P[i].id<=mid?l++:r++]=P[i];
	for(int i=L; i<=R; ++i)P[i]=C[i];
	Solve(L,mid);
	for(int i=L; i<=mid; ++i)
	{
		while(tp>1&&Q[tp].Slp(Q[tp-1])<P[i].Slp(Q[tp]))--tp;
		Q[++tp]=P[i];
	}
	for(int i=mid+1; i<=R; ++i)
	{
		while(tp>1&&Q[tp].Slp(Q[tp-1])<P[i].k)--tp;
		dp[P[i].id]=max(dp[P[i].id],P[i].Get(Q[tp]));
	}
	Solve(mid+1,R);
	l=L,r=mid+1; int p=L;
	while(l<=mid&&r<=R)C[p++]=P[P[l].x<P[r].x?l++:r++];
	while(l<=mid)C[p++]=P[l++];while(r<=R)C[p++]=P[r++];
	for(int i=L; i<=R; ++i)P[i]=C[i];
}
int main()
{
	cin>>n>>dp[0];
	for(int i=1; i<=n; ++i)P[i].read(i);
	sort(P+1,P+n+1,cmp); Solve(1,n);
	printf("%.3f\n",dp[n]);
}