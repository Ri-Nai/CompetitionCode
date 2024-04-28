#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int A[N],B[N],C[N],ans[N],cnt[N],last3[N],last2[N],last[N],len,n,m;
void Add(int x,int y){while(x<=n)C[x]+=y,x+=x&-x;}
int Sum(int x){int res=0;while(x)res+=C[x],x^=x&-x;return res;}
struct Que
{
	int id,L,R;
	void read(int i){id=i;scanf("%d%d",&L,&R);}
	bool operator <(const Que &_)const
	{
		return R<_.R;
	}
}Q[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[i]=A[i];
	sort(B+1,B+n+1);len=unique(B+1,B+n+1)-B-1;
	for(int i=1;i<=n;++i)A[i]=lower_bound(B+1,B+len+1,A[i])-B;
	for(int i=1;i<=m;++i)Q[i].read(i);
	//fill(last+1,last+n,1);
	int now=1;sort(Q+1,Q+m+1);
	for(int i=1;i<=m;++i)
	{
		while(now<=Q[i].R)
		{
			int x=A[now];
			if(last2[x])Add(last3[x]+1,-1),Add(last2[x]+1,1);
			if(last[x])Add(last2[x]+1,1),Add(last[x]+1,-1);
			last3[x]=last2[x];last2[x]=last[x];last[x]=now;
			++now;
		}
		// for(int j=1;j<=n;++j)Rn_3(i,j,Sum(j));
		ans[Q[i].id]=Sum(Q[i].L);
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
}
/*
6
2
1 1 4 5 1 4
5 6
2 4
*/