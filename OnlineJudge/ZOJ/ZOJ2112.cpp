#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,A[maxn],B[maxn<<1],len,len1,len2,q1[maxn],q2[maxn];
struct Que
{
	int x,y,k;
	bool flag;
	void read()
	{
		char tmp[2];scanf("%s",tmp);
		if(tmp[0]=='Q')flag=1,scanf("%d%d%d",&x,&y,&k);
		else flag=0,scanf("%d%d",&x,&y),B[++len]=y;
	}
}C[maxn];
int tot,RT[maxn],sum[maxn*20],ls[maxn*20],rs[maxn*20];
void updata(int L,int R,int x,int y,int &rt)
{
	if(!rt)rt=++tot;
	sum[rt]+=y;
	if(L==R)return ;
	int mid=L+R>>1;
	if(x<=mid)updata(L,mid,x,y,ls[rt]);
	else updata(mid+1,R,x,y,rs[rt]);
}
void Add(int id,int x,int y){while(id<=n)updata(1,len,x,y,RT[id]),id+=id&-id;}
void make_id(int id,int *A,int &x){x=0;while(id)A[++x]=RT[id],id-=id&-id;}
int query(int L,int R,int k)
{
	if(L==R)return L;
	int mid=L+R>>1,cnt=0;
	for(int i=1;i<=len1;++i)cnt+=sum[ls[q1[i]]];
	for(int i=1;i<=len2;++i)cnt-=sum[ls[q2[i]]];
	if(cnt>=k)
	{
		for(int i=1;i<=len1;++i)q1[i]=ls[q1[i]];
		for(int i=1;i<=len2;++i)q2[i]=ls[q2[i]];
		return query(L,mid,k);
	}
	else
	{
		for(int i=1;i<=len1;++i)q1[i]=rs[q1[i]];
		for(int i=1;i<=len2;++i)q2[i]=rs[q2[i]];
		return query(mid+1,R,k-cnt);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),B[++len]=A[i];
	for(int i=1;i<=m;++i)C[i].read();
	sort(B+1,B+len+1);len=unique(B+1,B+len+1)-B-1;
	for(int i=1;i<=n;++i)
		A[i]=lower_bound(B+1,B+len+1,A[i])-B;
	for(int i=1;i<=m;++i)
		if(!C[i].flag)C[i].y=lower_bound(B+1,B+len+1,C[i].y)-B;
	for(int i=1;i<=n;++i)Add(i,A[i],1);
	for(int i=1;i<=m;++i)
	{
		if(C[i].flag)
		{
			make_id(C[i].y,q1,len1);
			make_id(C[i].x-1,q2,len2);
			printf("%d\n",B[query(1,len,C[i].k)]);
		}
		else
		{
			Add(C[i].x,A[C[i].x],-1);
			Add(C[i].x,C[i].y,1);
			A[C[i].x]=C[i].y;
		}
	}
}