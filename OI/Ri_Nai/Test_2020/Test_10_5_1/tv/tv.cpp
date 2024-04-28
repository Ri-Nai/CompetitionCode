#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
const int N=1e5+5;
int n,m,p,nxt[N][18],C[N];
int rd()
{
	int t=0,c,f=0;while(!isdigit(c=getchar()))f|=c=='-';
	while(isdigit(c))t=(t<<1)+(t<<3)+(c^48),c=getchar();
	return f?-t:t;
}
struct Seg
{
	int l,r;
	bool operator <(const Seg &_)const
	{
		return r<_.r;
	}
}A[N],B[N];
int LW(int x)
{
	int L=1,R=p,ans=p+1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(B[mid].l>=x)R=mid-1,ans=mid;
		else L=mid+1;
	}
	return ans;
}
void Pre()
{
	n=rd();
	for(int i=1;i<=n;++i)
		A[i].l=rd(),A[i].r=rd();
	sort(A+1,A+n+1);
	for(int i=1,mxL=0;i<=n;++i)
		if(A[i].l>mxL)mxL=A[i].l,B[++p]=A[i];
	for(int i=1,now=1;i<=p;++i)
	{
		while(now<=p&&B[now].l<B[i].r)++now;
		nxt[i][0]=now;
	}
	for(int i=1;i<18;++i)
		for(int j=1;j<=p;++j)
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	B[0].r=B[p+1].r=1e9;
}
int main()
{
	FILE("tv");
	Pre();
	for(int l,r,Q=rd();Q--;)
	{
		l=rd();r=rd();
		int t=LW(l),ans=0;
		if(t==p+1)
		{
			puts("0");
			continue;
		}
		for(int i=17;~i;--i)
			if(B[nxt[t][i]].r<=r)
				t=nxt[t][i],ans|=1<<i;
		printf("%d\n",ans+1);
	}
	FCLS();
}